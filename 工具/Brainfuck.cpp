/*

字符 	含义
>		指针加一
<		指针减一
+		指针指向的字节的值加一
-		指针指向的字节的值减一
.		输出指针指向的单元内容（ASCⅡ码）
,		输入内容到指针指向的单元（ASCⅡ码）
[		如果指针指向的单元值为零，向后跳转到对应的]指令的次一指令处
]		如果指针指向的单元值不为零，向前跳转到对应的[指令的次一指令处

*/

#include <cstdio>
#include <cstring>

class autobuf_t {
public:
    enum {
        BLOCK_SIZE = 64
    };

    autobuf_t() {
        len = BLOCK_SIZE * 2;

        buf = new char[len];
        memset(buf, 0, len);

        now = buf + BLOCK_SIZE;
    }

    ~autobuf_t() {
        delete buf;
    }

    void left() {
        if (now == buf) {
            char * p = new char[len + BLOCK_SIZE];
            memset(p, 0, BLOCK_SIZE);
            memcpy(p + BLOCK_SIZE, buf, len);
            delete buf;

            buf = p;
            now = p + BLOCK_SIZE;
            len += BLOCK_SIZE;
        }
        now--;
    }

    void right() {
        if (now + 1 == buf + len) {
            char * p = new char[len + BLOCK_SIZE];
            memcpy(p, buf, len);
            memset(p + len, 0, BLOCK_SIZE);
            delete buf;

            buf = p;
            now = p + len - 1;
            len += BLOCK_SIZE;
        }
        now++;
    }

    void increment() {
        ++*now;
    }

    void decrement() {
        --*now;
    }

    bool getch(FILE * f) {
       int c = fgetc(f);
       if (c != EOF)
           *now = c;
       return c != EOF;
    }

    void putch(FILE * f) {
        fputc(*now, f);
    }

    char val() {
        return *now;
    }

private:
    autobuf_t(const autobuf_t&);
    void operator = (const autobuf_t&);

    char * buf;
    char * now;
    size_t len;
};

class bfsrc_t {
public:
    bfsrc_t(const char * fname):buf(NULL),jump_tbl(NULL) {
        memset(errbuf, 0, sizeof(errbuf));

        FILE * f = fopen(fname, "r");
        if (f == NULL) {
            snprintf(errbuf, sizeof(errbuf), "Failed to open file");
            return;
        }

        fseek(f, 0, SEEK_END);
        size_t fsize = ftell(f);
        buf = new char[fsize + 1];

        fseek(f, 0, SEEK_SET);
        fread(buf, fsize, 1, f);
        fclose(f);

        buf[fsize] = 0;
        preprocess();
    }

    ~bfsrc_t() {
        delete buf;
        delete [] jump_tbl;
    }

    const char * error() {
        return errbuf[0] ? errbuf : NULL;
    }

    const char * c_str() {
        return errbuf[0] ? NULL : buf;
    }

    const char * jump(int * jid) {
        int j = *jid;
        *jid = jump_tbl[j].jump_id;
        return jump_tbl[*jid].pos;
    }

private:
    bfsrc_t(const bfsrc_t&);
    void operator = (const bfsrc_t&);

    struct jump_node_t {
        const char * pos;
        int line;
        int column;
        int jump_id;
    };

    void preprocess() {
        int n = 0;
        for (const char *p = buf; *p; p++) {
            if (*p == '[' || *p == ']')
                n++;
        }

        if (n == 0)
            return;

        jump_tbl = new jump_node_t[n];

        int line = 1;
        int column = 0;
        int i = 0;
        for (const char *p = buf; *p; p++) {
            column++;
            if (*p == '[' || *p == ']') {
                jump_tbl[i].pos = p;
                jump_tbl[i].line = line;
                jump_tbl[i].column = column;
                jump_tbl[i].jump_id = -1;
                i++;
            } else if (*p == '\n') {
                line++;
                column = 0;
            }
        }

        for (i = 0; i < n; i++) {
            if (jump_tbl[i].jump_id != -1)
                continue;

            int direction = (jump_tbl[i].pos[0] == '[') ? 1 : -1;
            int count = 1;
            for (int x = i + direction; x >= 0 && x < n; x += direction) {
                if (jump_tbl[x].pos[0] == jump_tbl[i].pos[0]) {
                    count++;
                } else {
                    count--;
                    if (count == 0) {
                        jump_tbl[i].jump_id = x;
                        jump_tbl[x].jump_id = i;
                        break;
                    }
                }
            }
        }

        for (i = 0; i < n; i++) {
            if (jump_tbl[i].jump_id == -1) {
                snprintf(errbuf, sizeof(errbuf), "[] unmatched @ line:%d column:%d", jump_tbl[i].line, jump_tbl[i].column);
                break;
            }
        }
    }

    char * buf;
    jump_node_t * jump_tbl;
    char errbuf[64];
};

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <brainfuck_src>\n", argv[0]);
        return 1;
    }

    bfsrc_t code(argv[1]);
    if (code.error()) {
        printf("%s\n", code.error());
        return 2;
    }

    autobuf_t v;

    int jump_id = -1;
    for (const char * p = code.c_str(); *p; p++) {
        switch (*p) {
            case '<' : v.left(); break;
            case '>' : v.right(); break;
            case '+' : v.increment(); break;
            case '-' : v.decrement(); break;
            case '.' : v.putch(stdout); fflush(stdout); break;
            case ',' : v.getch(stdin); break;
            case '[' :
                jump_id++;
            loop :
                if (v.val() == 0)
                    p = code.jump(&jump_id);
                break;
            case ']' :
                jump_id++;
                p = code.jump(&jump_id);
                goto loop;
        }
    }

    return 0;
}

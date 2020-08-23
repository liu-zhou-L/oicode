#include <easyx.h>
#include <thread>
#include <conio.h>
#include <cstdio>

const int NEXT[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
enum DIRECTION {
	RIGHT, LEFT, DOWN, UP
};

bool START;
int NEXTDIRECTION = DOWN;

IMAGE snake_head, snake_body, startbutton1, startbutton2, white;

struct listnode {
	int x, y;
	listnode* next;
	listnode* last;
	listnode() {
		next = this;
		last = this;
		x = 0;
		y = 0;
	}
}root, * head, * end;

void list_add() {
	end->next = new listnode;
	end->next->last = end;
	end->next->x = end->x;
	end->next->y = end->y;
	end = end->next;
}

void snake_point() {
	listnode *Temp = head;
	putimage(Temp->x, (Temp->y - 1) * 20, &snake_head);
	while (Temp->next != Temp) {
		Temp = Temp->next;
		putimage(Temp->x, (Temp->y - 1) * 20, &snake_body);
	}
}

void init() {
	head = &root;
	end = &root;
	loadimage(&snake_head, _T("picture//head.png"), 20, 20);
	loadimage(&snake_body, _T("picture//body.png"), 20, 20);
	loadimage(&startbutton1, _T("picture//startbutton1.png"), 100, 50);
	loadimage(&startbutton2, _T("picture//startbutton2.png"), 100, 50);
	loadimage(&white, _T("picture//white.png"), 20, 20);
}

void Button(int a, int b, int len, int wid, IMAGE &one, IMAGE &two) {
	putimage(a, b, &one);
	MOUSEMSG Temp;
	do {
		Temp = GetMouseMsg();
		if (Temp.mkLButton) {
			if (Temp.x >= a && Temp.x <= a + len - 1 && Temp.y >= b && Temp.y <= b + wid - 1) {
				putimage(a, b, &two);
				Beep(900, 50);
				Sleep(20);
				return;
			}
		}
		//FlushMouseMsgBuffer();
		Sleep(15);
	} while (1);
}

void start_Button() {
	Button(175, 125, 100, 50, startbutton1, startbutton2);
	START = true;
	return;
}

int main() {
	listnode* temp;
	initgraph(450, 300, EW_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	init();
	while (1) {
		START = false;
		std::thread t1(start_Button);
		t1.detach();
		while (!START);
		temp = end;
		cleardevice();
		for (int i = 9; i >= 1; i--) {
			list_add();
			end->x = 1;
			end->y = i;
		}
		head->x = 1;
		head->y = 10;
		NEXTDIRECTION = DOWN;
		while (1) {
			snake_point();
			if (_kbhit()) {
				char KEY_DOWN = _getch();
				switch (KEY_DOWN) {
					case 'a':
						NEXTDIRECTION = LEFT;
						break;
					case 'd':
						NEXTDIRECTION = RIGHT;
						break;
					case 's':
						NEXTDIRECTION = DOWN;
						break;
					case 'w':
						NEXTDIRECTION = UP;
						break;
				}
			}
			putimage(end->x, (end->y - 1) * 20, &white);
			temp = end;
			while (temp != head) {
				temp->x = temp->last->x;
				temp->y = temp->last->y;
				temp = temp->last;
			}
			head->x += NEXT[NEXTDIRECTION][0];
			head->y += NEXT[NEXTDIRECTION][1];
			if (head->x > 20) {;
				head->x = 1;
			}
			if (head->x < 1) {
				head->x = 20;
			}
			if (head->y > 15) {
				head->y = 1;
			}
			if (head->y < 1) {
				head->y = 15;
			}
			//printf("%d %d ", head->x, head->y);
			temp = head;
			while (temp != end) {
				printf("%d %d ", temp->x, temp->y);
				temp = temp->next;
			}
			printf("\n");
			Sleep(500);
		}
		while (1);
	}
	closegraph();			// ¹Ø±Õ»æÍ¼´°¿Ú
	return 0;
}
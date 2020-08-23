#include <cstdio>
#include <vector>

using namespace std;

struct node {
	int head, last;
	bool operator>(const node &that) const {
		if (this->head != that.head) return this->head > that.head;
		return this->last > that.last;
	}
};

int n, len;
vector<node> v;

void bubble_sort() {
	node temp;
    for (int i = 1; i <= n- 1; i++) {
    	for (int j = 1; j <= n - 1 - i; j++) {
	    	if (v[j] > v[j + 1]) {
	            temp = v[j];
	            v[j] = v[j + 1];
	            v[j + 1] = temp;
	        }	
		}
	}  
}

int main() {
	scanf("%d", &n);
	len = n;
	v.resize(n + 5);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &v[i].head, &v[i].last);
	}
	bubble_sort();
	vector<node>::iterator it = v.begin();
	vector<node>::iterator It = v.begin();
	//It++;
	it++;
	for (int i = 1; i <= n && it != v.end(); i++) {
		if (it->head <= It->last) {
			It->last = it->last;
			it = v.erase(it);
			len--;
		} else {
			It++;
			it++;
		}
	}
	for (int i = 1; i <= len; i++) {
		printf("%d %d\n", v[i].head, v[i].last);
	}
	return 0;
}

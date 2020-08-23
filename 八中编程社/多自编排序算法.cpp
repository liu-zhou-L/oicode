#include<cstdio>
#include<cstring>

int a[100005], n;

void Swap(int &i, int &j) {
	i += j;
	j = i - j;
	i -= j;
}

void Selection_Sort(int array[], int headindex, int lastindex) {
	if(headindex > lastindex) return;
	for(int i = headindex + 1; i <= lastindex; i ++) {
		if(array[i] < array[headindex]) Swap(array[i], array[headindex]);
	}
	Selection_Sort(array, headindex + 1, lastindex);
}

void Bubble_Sort(int array[], int headindex, int lastindex) {
	if(headindex > lastindex) return;
	for(int i = headindex; i < lastindex; i ++) {
		if(array[i] > array[i + 1]) Swap(array[i], array[i + 1]);
	}
	Bubble_Sort(array, headindex, lastindex - 1);
}

void Merge_Sort(int array[], int headindex, int lastindex) {
	static int array2[1000005];
	if(headindex == lastindex) return;
	int m = (headindex + lastindex) / 2;
	Merge_Sort(array, headindex, m);
	Merge_Sort(array, m + 1, lastindex);
	int i, j, k;
	i = k = headindex;
	j = m + 1;
	while(i <= m && j <= lastindex) {
		if(array[i] <= array[j]) {
			array2[k ++] = array[i ++];
		}
		else {
			array2[k ++] = array[j ++];
		}
	}
	while(i <= m) {
		array2[k ++] = array[i ++];
	}
	while(j <= lastindex) {
		array2[k ++] = array[j ++];
	}
	for(int i = headindex; i <= lastindex; i ++) {
		array[i] = array2[i];
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	Merge_Sort(a, 1, n);
	for(int i = 1; i <= n; i ++) {
		printf("%d ", a[i]);
	}
	return 0;
}


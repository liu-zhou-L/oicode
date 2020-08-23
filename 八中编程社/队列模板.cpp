//¶ÓÁÐÄ£°å
#include <cstdio>

const int MAXN = 2 * 1e4 + 5;

template<class Type>
class Queue {
	public:
		Queue() {
			Queue::head = 0, Queue::ast = 1;
		}
		int size() {
			return Queue::last -Queue:: head - 1;
		}
		void push(Type operan) {
			if(Queue::last < MAXN) {
				Queue::unit[Queue::last++] = operan;
			}
		}
		void pop() {
			if(Queue::size() > 0) {
				Queue::last--;
			}
		}
		Type front() {
			if(Queue::size() > 0) {
				return Queue::unit[Queue::head];
			}
			return -1;
		}
		Type back() {
			if(Queue::size() > 0) {
				return Queue::unit[Queue::last - 1];
			}
			return -1;
		}
		bool empty() {
			if(Queue::size() == 0) {
				return true;
			}
			return false;
		}
	private:
		int head, last;
		Type unit[MAXN];
}; 


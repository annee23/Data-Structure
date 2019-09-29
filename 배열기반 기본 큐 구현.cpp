#include<iostream>
using namespace std;

struct Queue {
	static const int N = 5;
	int arr[N];
	int f = 0;
	int r = 0;
	int n = 0;	//size of Queue

	int size() {
		return n;
	}
	bool empty() {
		if (n == 0)
			return 1;
		else
			return 0;
	}
	void enqueue(int o) {
		if (size() != N) {
			n++;
			arr[r] = o;
			r = (r + 1) % N;
		}
	}
	int dequeue() {
		if (!empty()) {
			f = (f + 1) % N;
			n--;
			return arr[(f - 1 + N) % N];
		}

	}
};

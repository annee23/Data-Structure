#include<iostream>
#include<string>
using namespace std;
struct Node {
	Node* next = NULL;
	int n = 0;
	bool po = false;
};
struct Queue {
	Node* front = NULL;
	Node* rear = NULL;
	int size = 0;
	void push(int x) {
		Node* newN = new Node;
		newN->n = x;
		size++;
		if (rear == NULL) 
			rear = front = newN;
		else {
			rear->next = newN;
			rear = newN;
		}
	}
	int pop() {
		if (size != 0) {
			size--;
			Node* temp = front;
			int t = temp->n;
			if (size == 0)
				rear = front = NULL;
			else
				front = front->next;
			delete temp;
			return t;
		}
		else
			return -1;
	}

};
int maxd(Queue* q) {
	int max = 0;
	Node* it = q->front;			//iterator함부로 삭제하지 말기!!
	for (int i = 0; i < q->size; i++) {
		if (max < it->n)
		{
			max = it->n;
			it = it->next;
		}
		else
			it=it->next;
	}
	return max;
}
int print(Queue* q) {
	int count = 1;
	while (1) {
		if (q->front->n < maxd(q))
		{
			if (q->front->po)
			{
				q->push(q->pop());		//다시넣을때 bool변수 꼭 바톤터치하기!!
				q->rear->po = true;
			}
			else
				q->push(q->pop());
		}
		else {
			if (q->front->po)
				break;
			q->pop();
			count++;
		}
	}
	return count;
}
int main() {
	int n;
	cin>> n;
	for (int i = 0; i < n; i++) {
		int N, M;
		cin >> N >> M;
		Queue* myq = new Queue;
		for (int j = 0; j < N; j++) {
			int t;
			cin >> t;
			myq->push(t);
			if (M == j)
				myq->rear->po = true;		//노드자체에 표시하는게 제일 확실함
		}
		cout << print(myq) << "\n";
		delete myq;
	}
	return 0;
}
#include <iostream>
#include <string>
using namespace std;

struct Node {
	Node* next = NULL;
	int n = 0;
};
struct Queue {
	Node* head = NULL;
	Node* tail = NULL;
	int size = 0;
	int pop() {
		if (size == 0)
			return -1;
		size--;
		Node* temp = head;
		head = head->next;
		int t = temp->n;
		delete temp;
		return t;
	}
	void push(int x) {
		size++;
		Node* newN = new Node;
		newN->n = x;
		if (size == 1)
			head = tail = newN;
		else {
			tail->next = newN;
			tail = newN;
		}
	}
	void moveL(int x) {
		
		if (size > 1) {
			for(int i=0;i<x;i++)
				push(pop());
		}
	}
	void moveR(int x) {
		if (size > 1) {
			for (int i = 0; i < x; i++)
			{
				Node* temp = tail;
				Node* it = head;
				while(1)
				{
					if (it->next->next == NULL)
					{
						tail = it;
						it->next = NULL;
						break;
					}
					else
						it = it->next;
				}
				temp->next = head;
				head = temp;
			}
		}
	}
	int L(int x) {
		int count = 0;
		Node* it = head;
		while (1) {
			
			if (it->n == x)
				return count;
			else
			{
				it = it->next;
				count++;
			}
		}
	}
};

int main() {
	int n, m;
	int count = 0;
	cin >> n >> m;
	Queue* myQ = new Queue;
	for (int i = 0; i < n; i++) {
		myQ->push(i + 1);
	}
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		int a, b;
		a = myQ->L(t);
		b = myQ->size - a;
		if (myQ->head->n == t)
			myQ->pop();
		else if (a > b)
		{
			myQ->moveR(b);
			myQ->pop();
			count += b;
		}
		else
		{
			myQ->moveL(a);
			myQ->pop();
			count += a;
		}
	}
	cout << count;
	return 0;
}

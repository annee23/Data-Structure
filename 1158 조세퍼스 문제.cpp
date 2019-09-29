#include<iostream>
using namespace std;
struct Node {
	Node* prev = NULL;
	Node* next = NULL;
	int num = 0;

};
struct LL {
	Node* head = NULL;
	Node* curr = NULL;
	int size = 0;
	
	void push(int i) {
		size++;
		Node* newN = new Node;
		newN->num = i;
		if (curr == NULL) {
			curr = newN;
			head = newN;
		}
		else {
			curr->next = newN;
			newN->prev = curr;
			curr = newN;
		}
	}
	void move(int k) {
		if (k > 1) {
			for(int i=0;i<k-1;i++)
				curr = curr->next;
		}
	}
	int pop() {
		if (size != 0) {
			int r = curr->num;
			if (size == 1)
			{

				curr = NULL;
				size = 0;
				return r;
			}
			else {
				Node* temp = curr;
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				curr = curr->next;
				delete temp;
				size--;
				return r;
			}
		}
	}
};
int main() {
	int N, K;
	cin >> N >> K;
	LL myL;
	bool boo = true;
	for (int i = 1; i < N + 1; i++) {
		myL.push(i);
	}
	myL.curr->next = myL.head;
	myL.head->prev = myL.curr;
	myL.curr = myL.curr->next;

	for(int i=0;i<N+2;i++)
	{
		if (myL.size == N&&boo) {
			cout << "<";
			boo = false;
		}
		else if (myL.size == 0)
			cout << ">" << endl;
		else {
			if (i != N)
			{
				myL.move(K);
				cout << myL.pop() << ", ";
				
			}
			else
				cout << myL.pop();
		}
	}
	return 0;
}
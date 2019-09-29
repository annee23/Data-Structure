#include <iostream>
#include <string>
using namespace std;

bool boo = false;

struct Node {
	Node* prev = NULL;
	Node* next = NULL;
	char n = 0;
};

struct LL {
	Node* head = NULL;
	Node* curr = NULL;
	void L() {
		if (curr != head)
		{
			curr = curr->prev;
		}
	}
	void D() {
		if (curr->next != NULL) {
			curr = curr->next;
		}
	}
	void B() {
		if (curr != head)
		{
			Node* temp = curr;
			if (curr->next != NULL)
			{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				curr = curr->prev;
			}
			else {
				curr->prev->next = NULL;
				curr = curr->prev;
			}
			delete temp;
		}
	}
	void P(char $) {
		Node* newN = new Node;
		newN->n = $;
		if (!boo) {
			head = new Node;
			head->next = newN;
			newN->prev = head;
			curr = newN;
			boo = true;
		}
		else if (curr->next != NULL)
		{
			newN->next = curr->next;
			newN->prev = curr;
			curr->next = newN;
			newN->next->prev = newN;
			curr = newN;
		}
		else {
			newN->prev = curr;
			curr->next = newN;
			curr = newN;
		}
	}
};
int main() {
	string s;
	cin >> s;
	LL* myL = new LL;
	for (auto a : s) {
		myL->P(a);
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == 'L')
			myL->L();
		else if (c == 'D')
			myL->D();
		else if (c == 'B')
			myL->B();
		else
		{
			char $;
			cin >> $;
			myL->P($);
		}
		
	}
	Node* c = myL->head;
	while (1) {
		if (c->next != NULL)
		{
			cout << c->next->n;
			c = c->next;
		}
		else
			break;

	}
	return 0;
}
#include <iostream>
#include<string>
using namespace std;

struct Node {
	Node* next = NULL;
	char c = 0;
};
struct Q {
	Node* head = NULL;
	Node* tail = NULL;
	int si = 0;
	void enqueue(char x) {
		Node* newN = new Node;
		newN->c = x;
		if (head == NULL)
		{
			head = tail = newN;
			si++;
		}
		else
		{
			tail->next = newN;
			tail = newN;
			si++;
		}
	}
	char dequeue() {
		if (si != 0) {
		 if (si == 1)
		{
			Node* temp = head;
			char t = temp->c;
			head = tail = NULL;
			delete temp;
			si--;
			return t;
		}
		else
		{
			Node* temp = head;
			char t = temp->c;
			head = head->next;
			delete temp;
			si--;
			return t;
		}
		}
	}
};
int main() {
	int n;
	cin >> n;
	
	while (n--) {
		Q* origin = new Q;
		Q* temp = new Q;
		string s;
		cin >> s;
		bool boo = true;

		if (s.size() == 0)
		{
			cout << boolalpha << boo << endl;
			return 0;
		}
		for (auto a : s)
			origin->enqueue(a);
		while (origin->si!=0) {
			if (temp->head == NULL)
				temp->enqueue(origin->dequeue());
			else if (temp->tail->c == '(' && origin->head->c == ')')
			{
				temp->dequeue();
				origin->dequeue();
			}
			else if (temp->tail->c == '[' && origin->head->c == ']')
			{
				temp->dequeue();
				origin->dequeue();
			}
			else if (temp->tail->c == '{' && origin->head->c == '}')
			{
				temp->dequeue();
				origin->dequeue();
			}
			else
				temp->enqueue(origin->dequeue());
		}
		if (temp->si != 0)
			boo = false;
		cout <<boolalpha<< boo << endl;
		delete origin, temp;
	}
	return 0;
}
#include<iostream>
#include<string>

using namespace std;

struct Node{
	int n = 0;
	Node* next = NULL;
};
struct LL {
	Node* head = NULL;
	int size = 0;
	void addFront(int X) {
		Node* newN = new Node;
		if (head == NULL) {
			newN->n = X;
			head = newN;
		}
		else {
			newN->n = X;
			newN->next = head;
			head = newN;
		}

	}
	void removeFront() {
		if (head == NULL)
			cout << "-1\n";
		else {
			int temp = head->n;
			Node* tem = head;
			if (head->next != NULL) {
				
				head = head->next;

			}
			else {
				head = NULL;
			}
			delete tem;
			cout << temp << endl;
		}
	}
	void front() {
		if (head == NULL)
			cout << "-1\n";
		else
			cout << head->n << endl;
	}
	void empty() {
		if (head == NULL)
			cout << "1\n";
		else
			cout << "0\n";
	}
	void showList(){
		if (head == NULL)
			cout << "-1\n";
		else {
			Node* hh = head;
			while (1)
			{
				
				cout << hh->n << " ";
				if (hh->next == NULL)
					break;
				else {
					hh = hh->next;
				}
			}
			cout << endl;
			
		}

	}
	void addBack(int x) {
		Node* newN = new Node;
		if (head == NULL)
		{
			newN->n = x;
			head = newN;
		}
		else{
			Node* hh = head;
			while (1)
			{
				
				if (hh->next == NULL)
				{
					hh->next = newN;
					newN->n = x;
					break;
				}
				else {
					hh = hh->next;
				}
			}
			
	}
	}
};

int main() {
	int N;
	cin >> N;
	LL* myL = new LL;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (s == "addFront") {
			int nu;
			cin >> nu;
			myL->addFront(nu);
		}
		else if (s == "removeFront") {

			myL->removeFront();
		}
		else if (s == "front") {

			myL->front();
		}
		else if (s == "empty") {

			myL->empty();
		}
		else if (s == "showList") {

			myL->showList();
		}
		else
		{
			int nu;
			cin >> nu;
			myL->addBack(nu);
		}

	}
	return 0;
}

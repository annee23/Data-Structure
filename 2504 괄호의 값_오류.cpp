#include <iostream>
#include<string>
using namespace std;

struct Node {
	Node* next = NULL;
	char c = 0;
};
struct Stack {
	Node* top = NULL;
	int size = 0;
	void push(char ch) {
		size++;
		Node* newN = new Node;
		newN->c = ch;
		if (top == NULL)
			top = newN;
		else {
			
			newN->next = top;
			top = newN;

		}
	}
	char pop() {
		if (top != NULL) {
			if (size == 1){ 
				Node* temp = top;
				char r = top->c;
				top = NULL;
				delete temp;
				size--;
				return r;
			}
				
			else {
				Node* temp = top;
				char r = top->c;
				top = top->next;
				delete temp;
				size--;
				return r;

			}
		}
	}
};
int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int sum = 0;
	Stack* origin = new Stack;
	Stack* sub = new Stack;
	bool boo = false;
	if (s.size() % 2 == 1||s[0]==']'||s[0]==')')
	{
		cout << "0";
		boo = true;
		return 0;
	}
	int tt = 0;
	for (int i = s.size()-1; i >= 0; i--) {
		if (s[i] == '(' || s[i] == ')')
			tt++;
		origin->push(s[i]);
	}
	if(tt%2==1)
	{
		cout << "0";
		boo = true;
		return 0;
	}
	while (1) {
		
		if (origin->top == NULL) {
			while(sub->top!=NULL){
				sum += (int)sub->pop();
			}
			break;
		}
		else if (origin->top->c == '(') {
			sub->push('(');
			origin->pop();
		}
		else if (origin->top->c == '[') {
			sub->push('[');
			origin->pop();
		}
		else if (origin->top->c == ')') {

			if (sub->top->c == '(') {
				sub->pop();
				origin->pop();
				sub->push(2);
			}
			else if (sub->top->c == ')' || sub->top->c == '[' || sub->top->c == ']') {
				cout << "0";
				boo = true;
				break;
			}
			else { //숫자가 나오면~
				int t = (int)sub->top->c;
				if (sub->top->next != NULL && sub->top->next->c == '(') {
					sub->pop();
					sub->pop();
					sub->push(t * 2);
					origin->pop();
				}
				else if (sub->top->next != NULL && (sub->top->next->c == ')' || sub->top->next->c == '[' || sub->top->next->c == ']')) {
					cout << "0";
					boo = true;
					break;
				}
				else if (sub->top->next == NULL) {
					
					cout << "0";
					boo = true;
					break;
				}
				else {
					int t2 = (int)sub->top->next->c;
					sub->pop();
					sub->pop();
					sub->push(t + t2);
					continue;
				}

			}
		}
		else if (origin->top->c == ']') {
			if (sub->top->c == '[') {
				sub->pop();
				origin->pop();
				sub->push(3);
			}
			else if (sub->top->c == ')' || sub->top->c == '(' || sub->top->c == ']') {
				cout << "0";
				boo = true;
				break;
			}
			else { //숫자가 나오면~
				int t = (int)sub->top->c;
				if (sub->top->next != NULL && sub->top->next->c == '[') {
					sub->pop();
					sub->pop();
					sub->push(t * 3);
					origin->pop();
				}
				else if (sub->top->next != NULL &&(sub->top->next->c == ')' || sub->top->next->c == '(' || sub->top->next->c == ']') ){
					cout << "0";
					boo = true;
					break;
				}
				else if (sub->top->next == NULL){
					cout << "0";
					boo = true;
					break;
				}
				else {
					int t2 = (int)sub->top->next->c;
					sub->pop();
					sub->pop();
					sub->push(t+t2);
					continue;
				}
			}
		}
		
	}
	if (!boo)
		cout << sum;
	return 0;
}
#include<iostream>
#include<vector>
using namespace std;

struct Node {
	Node* pa = NULL;
	Node* ch1 = NULL;
	Node* ch2 = NULL;
	int n = 0;
};
vector<Node*> v;
Node* root = new Node;
void pre(int x,Node* N) {
	if (x < N->n)
	{
		if (N->ch1 == NULL) {
			Node* newN = new Node;
			newN->n = x;
			newN->pa = N;
			N->ch1 = newN;
			v.push_back(newN);
		}
		else pre(x, N->ch1);
	}
	else {
		if (N->ch2 == NULL) {
			Node* newN = new Node;
			newN->n = x;
			newN->pa = N;
			N->ch2 = newN;
			v.push_back(newN);
		}
		else pre(x, N->ch2);
	}
}
void post(Node* N) {
	if (N->ch1 != NULL)
		post(N->ch1);
	if (N->ch2 != NULL)
		post(N->ch2);
	cout << N->n << "\n";
}
int main() {
	int tmp = 0;
	cin >> tmp;
	root->n = tmp;
	v.push_back(root);
	while (cin >> tmp)
		pre(tmp,root);
	post(root);
	return 0;
}
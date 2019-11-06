#include<iostream>
#include<vector>
using namespace std;
//5639
struct Node {
	Node* pa = NULL;
	Node* ch[2] = { NULL, };
	int n = 0;
};
Node* root = new Node;
void pre(Node* N) {
	cout << N->n << "\n";
	if (N->ch[0] != NULL)
		pre(N->ch[0]);
	if (N->ch[1] != NULL)
		pre(N->ch[1]);
}
void post(Node* N) {
	if (N->ch[0] != NULL)
		post(N->ch[0]);
	if (N->ch[1] != NULL)
		post(N->ch[1]);
	cout << N->n << "\n";
}
void insert(int x, Node* N) {
	if (N->n < x) {
		if (N->ch[1] == NULL) {
			Node* newN = new Node;
			newN->n = x;
			newN->pa = N;
			N->ch[1] = newN;
		}
		else
			insert(x, N->ch[1]);
	}
	else {
		if (N->ch[0] == NULL) {
			Node* newN = new Node;
			newN->n = x;
			newN->pa = N;
			N->ch[0] = newN;
		}
		else
			insert(x, N->ch[0]);
	}
}
int main() {
	int t, n;
	cin >> n;
	bool roo = false;
	while(n--) {
		cin >> t;
		if (!roo)
		{
			root->n = t;
			roo = true;
			continue;
		}
		insert(t, root);
	}
	pre(root);
	post(root);
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;
struct Node {
	Node* pa = NULL;
	Node* ch[2] = { NULL,NULL };
	int n = 0;
};
int counter = 0;
void insert(int x, Node* N) {
	counter++;
	if (x < N->n) {
		if (N->ch[0] == NULL)
		{
			Node* newN = new Node;
			newN->n = x;
			N->ch[0] = newN;
			newN->pa =N->ch[0];
		}
		else
			insert(x, N->ch[0]);
	}
	else {
		if (N->ch[1] == NULL)
		{
			Node* newN = new Node;
			newN->n = x;
			N->ch[1] = newN;
			newN->pa =N->ch[1];
		}
		else
			insert(x, N->ch[1]);
	}
}
int main() {
	int n;
	cin >> n;
	Node* root = NULL;
	while (n--) {
		int t;
		cin >> t;
		if (root == NULL)
		{
			root = new Node;
			root->n = t;
		}
		else
			insert(t, root);
		cout << counter << endl;
	}
	return 0;
}
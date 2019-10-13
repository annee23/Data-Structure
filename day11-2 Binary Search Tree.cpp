#include<iostream>
#include<vector>
using namespace std;
struct Node {
	Node* pa = NULL;
	Node* ch[2] = { NULL,NULL };
	int n = 0;
};
int counter = 0;
int countm = 0;
Node* root = NULL;
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
void transPlant(Node* u, Node* v) {
	if (u->pa == NULL)
		root = v;
	else if (u == u->pa->ch[0])
		u->pa->ch[0] = v;
	else
		u->pa->ch[1];
	if (v != NULL)
		v->pa = u->pa;
}
Node* treeMin(Node* k) {
	Node* it = k;
	while (it->ch[0] != NULL)
	{
		it = it->ch[0];
		countm++;
	}
	return it;
}
void treeDel(Node* z) {
	if (z->ch[0] == NULL)
		transPlant(z, z->ch[1]);
	else if (z->ch[1] == NULL)
		transPlant(z, z->ch[0]);
	else {
		Node* y = treeMin(z->ch[1]);
		if (y->pa != z)
		{
			transPlant(y, y->ch[1]);
			y->ch[1] = z->ch[1];
			y->ch[1]->pa = y;
		}
		transPlant(z, y);
		y->ch[0] = z->ch[0];
		y->ch[0]->pa = y;
	}
}
int main() {
	int n, m;
	cin >> n>>m;

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
	}
	while (m--) {
		int t;
		cin >> t;
		Node* it = root;
		while (it->n != t) {
			if (it->n < t)
				it = it->ch[1];
			else
				it = it->ch[0];
		}
		treeDel(it);
		cout << countm << endl;
	}
	return 0;
}
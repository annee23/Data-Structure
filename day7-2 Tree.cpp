#include <iostream>
#include<vector>
using namespace std;

struct Node {
	Node* pa = NULL;
	vector<Node*>ch;
	int n = 0;
	int size = 0;
};

int countSize(Node* tree[26], int find,int sum) {
	for (int i = 0; i < tree[find - 1]->ch.size(); i++)
		 sum=countSize(tree, tree[find - 1]->ch[i]->n, sum);
	sum += tree[find - 1]->size;
	return sum;
}

int main() {
	int N, K;		//N:number of folders,K:folders to search 
	cin >> N >> K;
	Node* tree[26] = { NULL, };		//since numbers are not in order

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		Node* newN = new Node;
		newN->n = a;
		newN->size = b;
		tree[a - 1] = newN;
	}

	for (int i = 0; i < N; i++) {
		int p, t;
		cin >> p;
		while (1) {
			cin >> t;
			if (!t)
				break;
			tree[p-1]->ch.push_back(tree[t - 1]);
			tree[t - 1]->pa = tree[p - 1];
		}
	}
	while (K--)
	{
		int find;
		cin >> find;
		cout<<countSize(tree, find,0)<<endl;
	}
	return 0;
}
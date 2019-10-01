#include<iostream>
#include<vector>
using namespace std;
struct Node {
	Node* pa = NULL;
	vector<Node*>ch;
	int n = 0;
};

int main() {
	int N, M;
	cin >> N >> M;

	vector<Node*>v;

	for (int i = 0; i < N; i++) {	//initialize
		Node* newN = new Node;
		newN->n = i + 1;
		v.push_back(newN);
	}

	for (int i = 0; i < N; i++) {
		int p, t;
		cin >> p;

		while (1) {		//make children node
			cin >> t;
			if (t == 0)
				break;
			v[t - 1]->pa = v[p - 1];	//connect child and parent node
			v[p - 1]->ch.push_back(v[t - 1]);	//connect parent and child node
		}
	}
	for (int i = 0; i < M; i++) {
		int find;
		cin >> find;
		int count = 0;			//count ancestor
		Node* it = v[find - 1];
		while (it->pa != NULL)
		{
			it = it->pa;
			count++;
		}
		cout << count << "||";

		int S = v[find - 1]->ch.size();		//print all child node
		if (v[find - 1]->ch.empty())
			cout << 0;
		else {
			for (int j = 0; j < S; j++) {
				cout << v[find - 1]->ch[j]->n << " ";
			}
		}
		cout << endl;
	}
	return 0;
}

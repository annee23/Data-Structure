#include<iostream>
#include<vector>
using namespace std;
struct Node {
	Node* pa = NULL;
	vector<int> ch;
	int n = 0;
 };

void push(int x) {
	Node* newN = new Node;
	newN->n = x;
	
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<Node*>v;
	for(int i=0;i<N;i++) {
		Node* newN = new Node;
		newN->n = i + 1;
		v.push_back(newN);
		int t = -1;
		cin >> t;
		bool one = false;
		while (1) {
			cin >> t;
			if (t == 0&&one)
				break;
			newN->ch.push_back(t);
			if (t == 0)
				break;
			one = true;
		}
	}
	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		int S=v[t - 1]->ch.size();
		for(int j=0;j<S;j++) {
			cout << v[t - 1]->ch[j] << " ";
		}
		cout << endl;
	}
	return 0;
}

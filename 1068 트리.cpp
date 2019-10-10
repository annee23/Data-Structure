	#include <iostream>
	#include<vector>
	using namespace std;
	struct Node {
		vector<Node*>ch;
		int n = -1;
	};
	int countL = 0;
	void count(vector<Node*> t, int idx) {
		if (t[idx] == NULL||t[idx]->n==-1)	//끊긴 노드(예외처리)
			return;
		if (t[idx]->ch.size() == 0)			//리프 노드(카운트)
			countL++;
		else
		{
			if (t[idx]->ch.size() == 1 && t[idx]->ch[0]->n == -1)	//하나뿐인 자식노드 삭제된경우(부모가 리프이므로 카운트)
				countL++;
			else {
				for (int j = 0; j < t[idx]->ch.size(); j++)
				{
					if (t[idx]->ch[j]->n == -1)	//끊긴 자식(예외처리)
						continue;
					count(t, t[idx]->ch[j]->n);	//재귀 호출
				}
			}
		}
	}
	int main() {
		int N;
		cin >> N;
		vector<Node*>tree;
		Node* root = NULL;
		int p;
		for (int i = 0; i < N; i++) {
			Node* newN = new Node;
			newN->n = i;
			tree.push_back(newN);
		}
		for (int i = 0; i < N; i++) {
			cin >> p;
			if (p == -1)
				root = tree[i];
			else
				tree[p]->ch.push_back(tree[i]);
		}
		int cut;
		cin >> cut;
		if (tree[cut]==root)
		{
			cout << 0;
			return 0;
		}
		tree[cut]->n=-1;
		count(tree,root->n);	//because of line 32
		cout << countL;
		return 0;
	}
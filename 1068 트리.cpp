	#include <iostream>
	#include<vector>
	using namespace std;
	struct Node {
		vector<Node*>ch;
		int n = -1;
	};
	int countL = 0;
	void count(vector<Node*> t, int idx) {
		if (t[idx] == NULL||t[idx]->n==-1)	//���� ���(����ó��)
			return;
		if (t[idx]->ch.size() == 0)			//���� ���(ī��Ʈ)
			countL++;
		else
		{
			if (t[idx]->ch.size() == 1 && t[idx]->ch[0]->n == -1)	//�ϳ����� �ڽĳ�� �����Ȱ��(�θ� �����̹Ƿ� ī��Ʈ)
				countL++;
			else {
				for (int j = 0; j < t[idx]->ch.size(); j++)
				{
					if (t[idx]->ch[j]->n == -1)	//���� �ڽ�(����ó��)
						continue;
					count(t, t[idx]->ch[j]->n);	//��� ȣ��
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
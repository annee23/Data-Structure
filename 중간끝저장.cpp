#include <iostream>
#include<vector>
using namespace std;

struct Node {
	Node* pa = NULL;
	vector < Node* > ch;
	int wei = 0;
	int n = 0;
};
vector<Node*> v;
int n;
struct Tree {
	int size = 0;
	void init() {
		for (int i = 0; i < size; i++) {
			Node* newN = new Node;
			newN->n = i + 1;
			v.push_back(newN);
		}
	}
};

vector<int> we;
void srch(Node* i, int t) {
	Node* it = i;
	int temp = t;
	if (it->wei == 0)
		return;
	if (it->pa != NULL)
	{
		temp += it->wei;
		we.push_back(temp);
		it = it->pa;
		srch(it, temp);
	}
	if(it->ch.size() > 0) {
		int tt = temp;
		for (int j = 0; j < it->ch.size(); j++)
		{
			temp += it->ch[j]->wei;
			we.push_back(temp);
			srch(it, temp);
		}
		temp = tt;
	}
	return;
}
int main() {
	cin >> n;
	
	Tree* myT = new Tree;
	myT->size = n;
	myT->init();
	
	for (int i = 0; i < n-1; i++) {
		int arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];
		v[arr[1] - 1]->pa = v[arr[0] - 1];
		v[arr[0] - 1]->ch.push_back(v[arr[1] - 1]);
		v[arr[1] - 1]->wei = arr[2];
	}

	vector<int> leafbool;
	for (int i = 0; i < n; i++) {
		if (v[i]->ch.size()==0)
			leafbool.push_back(i);
	}

	vector<int> leafwei(n);
	for (int i = 0; i < leafbool.size(); i++) {
		Node* it = v[leafbool[i]];
		while (it != NULL)
		{
			leafwei[i] += it->wei;
			it = it->pa;
		}
	}
	int maxleaf = 0;
	int ml = 0;
	for (int i = 0; i < leafbool.size(); i++) {
		if (maxleaf < leafwei[i])
		{
			maxleaf = leafwei[i];
			ml=i;
		}
	}
	maxleaf = leafbool[ml]+1;	//얘가 리프노드중에 제일 먼 노드임
	srch(v[maxleaf - 1], 0);

	int realmax = 0;
	for (int i = 0; i < we.size();i++) {
		if (realmax < we[i])
			realmax = we[i];
	}

	cout << realmax << endl;

	return 0;
}

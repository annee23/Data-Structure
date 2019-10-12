#include<iostream>
#include<vector>
using namespace std;

struct Node {
	Node* pa = NULL;
	Node* lc = NULL;
	Node* rc = NULL;
	bool isL = false;
	int n = 0;
};
int main() {
	vector<Node*>heap;
	Node* root = NULL;
	Node* last = NULL;
	int n;
	cin >> n;
	while (n--) {
		int temp;
		cin >> temp;

		Node* newN = new Node;
		newN->n = temp;
		heap.push_back(newN);

		if (heap.size()==1)
			root = last=newN;
		else {
			if (last->isL)
			{
				last->pa->rc = newN;
				newN->pa = last->pa;
				last = newN;
			}
			else
			{
				while (!(last->isL || last == root))
					last = last->pa;
				if(last!=root)
					last = last->pa->rc;
				while (last->lc!=NULL)
					last = last->lc;
				newN->isL = true;
				last ->lc= newN;
				newN->pa = last;
				last = newN;
			}
			//node insert
			Node* it = newN;
			while (it->pa!=NULL&&it->n < it->pa->n)
			{
				int swap = it->n;
				it->n = it->pa->n;
				it->pa->n = swap;
				it = it->pa;
			}//swap
		}
	}
	for (auto a : heap)
		cout << a->n << " ";
	cout<<endl;
	//sort-start
	vector<int>sorted;
	vector<int>hp;		
	hp.push_back(0);
	for (auto a : heap)
		hp.push_back(a->n);
	while (hp.size()!=1) {
		int idx = 1;
		int swap = hp[1];			//swap root and last
		hp[1] = hp[hp.size() - 1];
		hp[hp.size() - 1] = swap;
		sorted.push_back(swap);
		hp.pop_back();
		while (1) {		//down heap
			if (idx * 2 >= hp.size() || (hp[idx] < hp[idx * 2] && idx*2+1==hp.size())||(hp[idx] < hp[idx * 2] && hp[idx] < hp[idx * 2 + 1]))
				break;
			if (idx*2+1==hp.size()||hp[idx * 2 + 1] > hp[idx * 2])
			{
				swap = hp[idx];
				hp[idx] = hp[idx * 2];
				hp[idx * 2] = swap;
				idx = idx * 2;
			}
			else
			{
				swap = hp[idx];
				hp[idx] = hp[idx * 2+1];
				hp[idx * 2+1] = swap;
				idx = idx * 2 + 1;
			}
		}
	}
	//sort-finish
	for (auto a : sorted)
		cout << a << " ";
	return 0;
}
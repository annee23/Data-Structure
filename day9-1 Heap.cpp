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
	return 0;
}
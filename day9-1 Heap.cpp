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

		if (heap.size()==0)
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
			while (newN->n < newN->pa->n)
			{
				Node* parent = newN->pa;
				newN->pa = parent->pa;
				if (parent->isL)
					parent->lc = newN;
				else					
				{
					parent->rc = newN;
					newN->isL=false;
				}
				if (newN->isL)
				{
					newN->lc = parent;
					parent->pa = newN;
					parent->isL = true;
				}
				else {
					newN->lc = parent->lc;
					parent->lc->pa = newN;
					newN->rc = parent;
					parent->pa = newN;
					parent->isL = false;
				}
			}//swap
		}
	}
	visit();
	return 0;
}
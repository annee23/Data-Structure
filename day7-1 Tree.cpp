#include<iostream>
#include<vector>
using namespace std;
struct Node {
	Node* pa = NULL;
	vector <Node*> ch;
	int n = 0;
};
void preod(vector<Node*> T, int i) {
	cout << T[i - 1]->n<<" " ;
	if (T[i - 1]->ch.size() != 0)
	{
		for (int j = 0; j < T[i - 1]->ch.size(); j++) {
			preod(T, T[i - 1]->ch[j]->n);
		}
	}
	if (i == 1)
		cout << endl;
}
void postod(vector<Node*> T, int i) {

	if (T[i - 1]->ch.size() != 0)
	{
		for (int j = 0; j < T[i - 1]->ch.size(); j++) {
			postod(T, T[i - 1]->ch[j]->n);
		}
	}
	cout << T[i - 1]->n<<" ";
	if (i == 1)
		cout << endl;
}
int main() {
	int n;
	cin >> n;
	vector<Node*> T;
	for (int i = 0; i < n; i++)
		T.push_back(NULL);
	while (n--) {
		int p;
		cin >> p;
		Node* newN = new Node;
		newN->n = p;
		T[p - 1] = newN;

		int t = -1;
		while (1) {		//Tree initialize
			cin >> t;
			if (t == 0)
				break;
			if (T[t - 1] == NULL)
			{
				Node* newN = new Node;
				newN->n = t;
				T[t - 1] = newN;

				newN->pa = T[p - 1];
				T[p - 1]->ch.push_back(newN);
			}
			else {
				T[t - 1]->pa = T[p - 1];
				T[p - 1]->ch.push_back(T[t - 1]);
			}
		}
	}
	preod(T, 1);
	postod(T, 1);
	return 0;
}
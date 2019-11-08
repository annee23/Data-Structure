#include<iostream>
#include<vector>
using namespace std;

struct Node {
	Node* pa = NULL;
	Node* ch1 = NULL;
	Node* ch2 = NULL;
	int n = 0;
};
Node* root = new Node;
void pre(vector<int>v) {
	int tsize = v.size();
	root->n = v[0];
	for (int i = 1; i < tsize; i++) {
		
	}
}
void post() {

}
int main(){
	int tmp = 0;
	vector<int> v;
	while (cin >> tmp) 
		v.push_back(tmp);
	pre(v);
	post();
	return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int sum = 0;
vector<int>v;
int sumof(int idx1, int idx2) {
	for (int i = 0; i < 9; i++) {
		if (i == idx1 || i == idx2)
			continue;
		else
			sum += v[i];
	}
	return sum;
}
int main() {
	int t, N = 9;
	while (N--) {
		cin >> t;
		v.push_back(t);
	}
	int a, b;
	bool out = false;
	for (int i = 8; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			sum = 0;
			if (sumof(j, i) == 100) {
				a = i, b = j;
				out = true;
				break;
			}
		}
		if (out)
			break;
	}
	for (int i = 0; i < 9; i++) {
		if (i == a || i == b)
			continue;
		else
			cout << v[i] << "\n";
	}
	return 0;
}
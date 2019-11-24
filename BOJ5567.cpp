#include<iostream>
#include<vector>
using namespace std;
//struct Vrt {
//	int data = 0;
//	int idx = 0;
//};
//struct Edg {
//	Vrt* S = NULL;
//	Vrt* D = NULL;
//}; 
int main() {
	int n, m, a, b;
	cin >> n;
	vector<int> frd(n+1,0);
	vector<int> ff;
	vector<vector<int>> e(n+1, vector<int>(n+1, 0));
	cin >> m;
	while (m--) {
		cin >> a >> b;
		e[a][b] = e[b][a] = 1;
	}
	for (int i = 1; i < n+1; i++) {
		if (e[1][i] == 1)
		{
			ff.push_back(i);
			frd[i] = 1;
		}

	}
	int tmp = ff.size();
	for (int i = 0; i < tmp; i++) {
		for (int j = 2; j < n + 1; j++)
		{
			/*if (e[1][j] == 1)
				continue;*/
			 if (e[ff[i]][j] == 1||e[j][ff[i]]==1)
			{
				frd[j]=1;
			}
		}
	}
	int c = 0;
	for (int i = 1; i < n + 1; i++) {
		if (frd[i] == 1)
			c++;
	}
	cout << c<< endl;

	return 0;
}
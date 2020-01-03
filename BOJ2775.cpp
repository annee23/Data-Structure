#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t, k, n;
	cin >> t;

	int arr[15][15];
	for (int i = 1; i < 15; i++)	//0층,1호들 초기화
	{
		arr[0][i] = i;
		arr[i][1] = 1;
	}//arr[a][b]=arr[a][b-1]+arr[a-1][b]/ arr[a][1]=arr[a-1][1]
	for (int i = 1; i < 15; i++) {
		for (int j = 2; j < 15; j++) {
			arr[i][j] = arr[i - 1][j]+arr[i][j-1];
		}
	}
	
	while (t--) {
		cin >> k >> n;
		cout << arr[k][n] << endl;
	}
	return 0;
}
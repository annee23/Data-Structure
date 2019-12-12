#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t, k, n;
	cin >> t;
	int arr[15][15];
	for (int i = 1; i < 15; i++)
	{
		arr[0][i] = i;
	}//arr[a][b]=arr[a][b-1]+arr[a-1][b]/ arr[a][1]=arr[a-1][1]
	for (int i = 1; i < 15; i++) {
		arr[i][1] = arr[i - 1][1];
		for (int j = 2; j < 15; j++) {
			arr[i][j] = arr[i - 1][j];
		}
	}
	
	while (t--) {
		cin >> k >> n;
		while (k--) {

		}
	}
}
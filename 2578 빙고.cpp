#include <iostream>

using namespace std;
int countt = 0;
void bingo(bool check[5][5]) {
	int bi = 0;
	for (int i = 0; i < 5; i++) {
		if (check[i][i] == true)
			bi++;
	}if (bi == 5) 
		countt++;
	
	bi = 0;
	for (int i = 0; i < 5; i++) {
		if (check[4 - i][i] == true)
			bi++;
	}if (bi == 5)
		countt++;

	bi = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (check[j][i] == true)
				bi++;
		}if (bi == 5) {
			countt++;
			bi = 0;
		}
		else
			bi = 0;
		
	}
	bi = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (check[i][j] == true)
				bi++;
		}if (bi == 5) {
			countt++;
			bi = 0;
		}
		else
			bi = 0;
	}
}

int main() {
	
	int bin[5][5];
	int call[25];
	bool bol = false;
	bool check[5][5] = { false, };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> bin[i][j];
		}
	}
	for (int i = 0; i < 25; i++) {
		int num;
		cin >> num;
		call[i] = num;
	}
	
	for (int k = 0; k < 25; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (call[k] == bin[i][j])
				{
					check[i][j] = true;
					bol = true;
					break;
				}
			}if (bol == true)
			{
				bol = false;
				break;
			}
		}
		bingo(check);
		if (countt < 3)
		{
			countt = 0;
		}
		else
		{
			cout << k + 1;
			break;
		}
	}
	return 0;
}
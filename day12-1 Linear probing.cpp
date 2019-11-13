#include<iostream>
#include<vector>
using namespace std;

struct item {
	int key{ 0 }, value{ 0 };
};
struct arr {
	item* data = NULL;
	bool flag = false;
};
arr HashArr[353333];
//int Max = 353333;
int ct = 1;
int hashfunc(int inp) {
	return inp % 353333;
}
//int hashfunc2(int inp) {
//	return (17 - (inp % 17));
//}
int main() {
	int N, M, t;
	cin >> N;
	while (N--) {
		cin >> t;
		item* newI = new item;
		newI->key = hashfunc(t);
		while (1) {
			if (!HashArr[newI->key].flag)
			{
				newI->value = t;
				HashArr[newI->key].data = newI;
				HashArr[newI->key].flag = true;
				break;
			}
			else {
				newI->key++;
			}
		}
	}
	cin >> M;
	while (M--) {
		cin >> t;
		int tmp = hashfunc(t);
		bool find = false;
		while (1) {
			if (HashArr[tmp].flag)
			{
				if (HashArr[tmp].data->value == t)
				{
					find = true;
					break;
				}
				else
				{
					tmp++;
					ct++;
				}
			}
			else break;
		}
		if (find)
			cout << 1 << " " << ct << endl;
		else
			cout << 0 << " " << ct << endl;
		ct = 1;
	}
	return 0;
}
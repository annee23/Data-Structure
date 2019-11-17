#include<iostream>
#include<vector>
using namespace std;

struct item {
	int key{ 0 }, value{ 0 };
};
struct arr {
	item* data = NULL;
	bool flag = false;		//if arr has item
};
arr HashArr[353333];
int hashfunc(int inp) {
	return inp % 353333;
}
int hashfunc2(int inp) {
	return (17 - (inp % 17));
}
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
				newI->key += hashfunc2(t);
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
					tmp+=hashfunc2(t);
				}
			}
			else break;
		}
		if (find)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
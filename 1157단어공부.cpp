#include<iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int cnt[26] = { 0, };
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 97)
			cnt[s[i] - 97]++;
		else
			cnt[s[i] - 65]++;
	}
	int boo = 0;
	int max = 0;
	int m = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max < cnt[i])
		{
			max = cnt[i];
			m = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] == max)
			boo++;

	}
	if (boo>1)
		cout << "?";
	else
		cout << (char)(m + 65);
	return 0;
}
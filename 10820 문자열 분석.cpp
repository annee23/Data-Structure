#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    vector<int> v[104];
    int N = -1;
    for (int i = 0; i < 100; i++) {
        N++;
        int small = 0, big = 0, num = 0, blank = 0;
        string s;
        getline(cin, s);
        if (s.length() == 0)
            break;  //개행문자확인
        for (int j = 0; j < s.size(); j++)
            v[i].push_back(s[j]);
        for (int j = 0; j < s.size(); j++)
        {
            if (v[i][j] == ' ')
                blank++;
            else if ((int)v[i][j] > 64 && (int)v[i][j] < 91)
                big++;
            else if ((int)v[i][j] > 96 && (int)v[i][j] < 123)
                small++;
            else
                num++;      //char이므로 '0'~'9'로하던가 (int)붙이던가해야함
        }
        v[i].push_back(blank);
        v[i].push_back(num);
        v[i].push_back(big);
        v[i].push_back(small);

        for (int j = 0; j < 4; j++)
        {
            cout << v[i].back() << " ";
            v[i].pop_back();
        }
        cout << "\n";
    }

    return 0;
}
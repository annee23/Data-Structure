#include<iostream>
#include<string>
#include <vector>

using namespace std;

char rot13(char c) {
    if (((int)c >= 65 && (int)c <= 90) || ((int)c >= 97 && (int)c <= 122))
    {
        int i = 0;
        i = (int)c;
        i += 13;
        return (char)i;
    }
    else
        return c;
}
int main() {
    string s;
    cin >> s;
    vector<char> v;
    vector<char>big;
    vector<char>small;
    for (auto a : s) {
        v.push_back(a);
    }
    for (int i = 65; i < 91; i++) {
        big.push_back((char)i);
    }
    for (int i = 65; i < 91; i++) {
        small.push_back((char)i);
    }

    for (auto b : v) {
        cout << rot13(b);
    }
    return 0;
}
#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<char> v;
    vector<int> in;
    for (int j = 0; j < 26;j++) {
        in.push_back(-1);
    }
    for (auto a : s) {
        v.push_back(a);
    }
    for (int i = 0; i < v.size();i++) {
        in[v[i] - 65] = i;
    }
    
    for (auto a : in) {
        cout << a << " ";
    }
}
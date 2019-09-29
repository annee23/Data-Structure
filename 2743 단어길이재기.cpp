#include<iostream>
#include<string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<char> v;
    for (auto a : s) {
        v.push_back(a);
    }
    int num = 0;
    for (auto i : v) {
        v.pop_back();
        num++;
    }
    cout << num;
}
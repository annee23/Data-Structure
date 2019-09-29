#include <iostream>
#include<string>
#include<stack>
using namespace std;

int fun(string s) {
    stack<char> st1;
    stack<char> st2;
    int count = 0;
    int size = s.length();
    
    for (int i = 0; i < size; i++) {
        if (s[i] == '(' && s[i + 1] != ')')
        {
            if (st2.size() != 0)
                count -= st2.size();
            st1.push(s[i]);
        }
        else if (st1.size() != 0&&s[i] == ')' && s[i - 1] == '(')
            st2.push(s[i]);
        else if(s[i]==')'&&s[i-1]!='(')
        {
            count += st1.size() * st2.size() + 1;
            st1.pop();
            while (st2.size() != 0)
                st2.pop();
        }
    }
    return count;
}
int main() {
    string s;
    cin >> s;
    cout << fun(s);
}

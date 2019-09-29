#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node* front;
    char par;
};
struct Stack {
    Node* top;
};
//홀수/)시작/(끝
string isVPS(string st) {
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < st.length(); i++) {
        if (st[i] == '(')
            count1++;
        else
            count2++;
    }
    return count1 == count2 ? "YES" : "NO";
}
int main(){
    int num;
    string myString;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> myString;
        if (num % 2 == 1 || myString[0] == ')' || myString[myString.length() - 1] == '(')
            cout << "NO" << endl;
        else
            cout << isVPS(myString) << endl;
    }
    return 0;
 }

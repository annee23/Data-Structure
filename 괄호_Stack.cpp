#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node* front = NULL;
    char par = NULL;
};
struct Stack {
    Node* top = NULL;
};
void push(Stack* sta, char c) {
    Node* newNode = new Node;
    if (sta->top != NULL)
        newNode->front = sta->top;
    sta->top = newNode;
    newNode->par = c;
}
bool pop(Stack* sta) {
    if (sta->top == NULL)
        return false;
    Node* temp = sta->top;
    if (sta->top->front != NULL)
        sta->top = sta->top->front;
    else
        sta->top = NULL;
    delete temp;
    return true;
}

string isVPS(string st) {
    Stack* myStack = new Stack;
    int size = st.length();
    for (int i = 0; i < size; i++) {
        push(myStack, st[i]);
        if (myStack->top->par == ')')
        {
            pop(myStack);
            if (!pop(myStack))
                return "NO";
        }
    }
    if (myStack->top != NULL)
        return "NO";
    return "YES";
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

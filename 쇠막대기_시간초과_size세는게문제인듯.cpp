#include <iostream>
#include<string>
using namespace std;

struct Node {
    Node* pre = NULL;
    char data = 0;
};
struct Stack {
    Node* top = NULL;
    void push(char cc) {
        Node* newN = new Node;
        newN->pre = top;
        top = newN;
        newN->data = cc;
    }
    char pop() {
        Node* temp = top;
        char ret = top->data;
        top = top->pre;
        delete temp;
        return ret;
    }
    int size() {
        Node* iter = top;
        if (top == NULL)
            return 0;
        int count = 1;
        while (iter->pre != NULL) {
            iter = iter->pre;
            count++;
        }
        return count;
    }

};
int fun(string s) {
    Stack* st1 = new Stack;
    Stack* st2 = new Stack;
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' && s[i + 1] != ')')
        {
            if (st2->size() != 0)
                count -= st2->size();
            st1->push(s[i]);
        }
        else if (st1->size() != 0 && s[i] == ')' && s[i - 1] == '(')
            st2->push(s[i]);
        else if (s[i] == ')' && s[i - 1] != '(')
        {
            count += st1->size() * st2->size() + 1;
            st1->pop();
            while (st2->size() != 0)
                st2->pop();
        }
    }
    return count;
}
int main() {
    string s;
    cin >> s;
    cout << fun(s);
}

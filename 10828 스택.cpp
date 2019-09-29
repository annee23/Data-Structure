#include<iostream>
#include<string>
using namespace std;

int count1 = 0;
struct Node {
    Node* front = NULL;
    int data = 0;
};
struct stack {
    Node* top = NULL;
};

void push(stack* st,int x) {
    extern int count1;
    Node* newNode = new Node;
    if (st->top == NULL) {
        st->top = newNode;
        newNode->data = x;
    }
    else
    {
        newNode->front = st->top;
        newNode->data = x;
        st->top = newNode;
    }
    count1++;
}
void pop(stack* st) {
    extern int count1;
    if (st->top == NULL) 
        cout << "-1\n";
   

    else
    {
        int temp = st->top->data;
        Node* tempN = st->top;
        if (st->top->front != NULL)
        {
            st->top = st->top->front;
        }
        else
            st->top = NULL;
        delete tempN;
        cout << temp << endl;
        count1--;
    }
   
}
void size(stack* st) {
    extern int count1;
    cout << count1 << endl;
}
void empty(stack* st) {
    if (st->top == NULL)
        cout << "1\n";
    else
        cout << "0\n";
}
void top(stack* st) {
    if (st->top == NULL)
        cout << "-1\n";
    else
        cout << st->top->data << endl;
}

int main() {
    string s;
    int n;

    int N;
    cin >> N;
 
    stack myStack;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s == "push")
        {
            cin >> n;
            push(&myStack, n);
        }
        else if (s == "top")
            top(&myStack);
        else if (s == "pop")
            pop(&myStack);
        else if (s == "size")
            size(&myStack);
        else
            empty(&myStack);
    }
    return 0;
}
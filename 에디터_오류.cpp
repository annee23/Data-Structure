#include <iostream>
#include <string>

using namespace std;
static int c_B = 0;
struct Node {
    Node* front = NULL;
    Node* after = NULL;
    char data = NULL;
};
struct Stack {
    Node* top = NULL;

};
void push(Stack* sta, char c) {
    Node* newNode = new Node;
    if (sta->top != NULL)
    {
        newNode->front = sta->top;
        sta->top->after = newNode;
    }
    sta->top = newNode;
    newNode->data = c;
}

void L(Stack* sta) {
    if (sta->top->data != '@'&&sta->top->front != NULL)
        sta->top = sta->top->front;
}
void D(Stack* sta) {
    if (sta->top->after != NULL)
        sta->top = sta->top->after;
}
void B(Stack* sta) {
    if (sta->top->data != '@' && sta->top->front != NULL) {
        Node* temp = sta->top;
        sta->top = sta->top->front;
        sta->top->after = temp->after;
        temp->after->front = sta->top;
        delete temp;
        c_B++;
    }
}
void P(Stack* sta, char $) {
    Node* newN = new Node;
    if (sta->top->after == NULL)
        push(sta, $);
    else
    {
        sta->top->after = newN;
        newN->front = sta->top;
        newN->after = sta->top->after;
        sta->top->after->front = newN;
        newN->data = $;
        sta->top = newN;
    }
    
}
//stack 처음 만들때 시작노드 추가생성
int main(){
    int num;
    string myString;
    Stack* myStack = new Stack;
    cin >> myString;
    cin >> num;
    push(myStack, '@');

    int c_P = 0;
    
    for (auto a : myString) 
        push(myStack, a);

    for (int i = 0; i < num; i++) {
        char c;
        cin >> c;
        if (c == 'L')
            L(myStack);
        else if (c == 'D')
            D(myStack);
        else if (c == 'B')
        
            B(myStack);
        else
        {
            char s;
            cin >> s;
            P(myStack, s);
            c_P++;
        }
    }
    for(unsigned int i=0;i<(myString.length()+c_P-c_B);i++)
        L(myStack);
    D(myStack);
    for(unsigned int i=0;i< (myString.length() + c_P - c_B); i++)
    {
        cout << myStack->top->data;
        D(myStack);
    }

    return 0;
 }

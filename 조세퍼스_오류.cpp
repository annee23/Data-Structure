#include<iostream>
using namespace std;

struct Node {
    Node* next=NULL;
    int data=0;
};
struct List {
    Node* head = NULL;
    Node* tail = NULL;
   
 
};
void pushBack(List* list, int d) {
    Node* newNode = new Node; 
    if(list->tail!=NULL)
    list->tail->next = newNode;
   
    list->tail = newNode;
    newNode->data = d;
};
Node* movee(Node* N,int th1) {
    int count = 1;
    if (count != th1) {
        return movee(N->next, th1-1);
    }
    else
        return N;
};

void remove(List* list, int th2,int n) {
    int count = 1;
    Node* pp = list->head;
    while (count <= n) {
        Node* p = movee(pp, th2 - 1);
        int temp = p->next->data;
        p->next = p->next->next;
        cout << temp << " ";
        ++count;
        pp = p->next;
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    List* jose=new List;

    for (int i = 0; i < N; ++i) {
        pushBack(jose, i+1);
        if (i == 0)
        {
            jose->head = jose->tail;
            jose->head->next = jose->tail;
            jose->tail->next = jose->head;
        }

    }
    int n = N;

    remove(jose, K, N);
      
    
    return 0;
}
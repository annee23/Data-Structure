#include <iostream>
using namespace std;

struct Node {
    Node* next = NULL;
    int data = 0;
};

struct List {
    Node* tail = NULL;
    Node* head = NULL;
};

void add(List* list, int size) {
    for(int i=0;i<size;i++) {
        Node* newNode = new Node;
        if (list->tail == NULL)
        {
            list->tail = newNode;
            list->head = newNode;
        }
        else
            list->tail->next = newNode;
        list->tail = newNode;
        newNode->data = i + 1;
    }
    list->tail->next = list->head;
}

Node* mov(Node* pp) {
    return pp->next;
}
void remov(List* list,int k, int n) {
    Node* ppp=list->tail;
    Node* temp=NULL;
    if (k == 1) {
        ppp = list->head;
        for (int j = 0; j < n; j++) {
            if (j == 0)
                cout << "<" << ppp->data << ", ";
            else if (j == n - 1)
                cout << ppp->data << ">";
            else
                cout << ppp->data << ", ";
            temp = ppp;
            ppp = ppp->next;
            delete temp;

        }
    }
    else
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < k - 1; i++) {
                ppp = mov(ppp);
        
            }
            if (j == 0)
                cout << "<" << ppp->next->data << ", ";
            else if (j == n - 1)
                cout << ppp->next->data << ">";
            else
                cout << ppp->next->data << ", ";
            temp = ppp->next;
            ppp->next = ppp->next->next;
            delete temp;

        }
}

int main() {
    int N, K;
    cin >> N >> K;
    List* mylist = new List;
    add(mylist, N);
    if(N==1&&K==1)
        cout << "<1>";
    else
        remov(mylist, K, N);
    delete mylist;
    mylist = NULL;

}
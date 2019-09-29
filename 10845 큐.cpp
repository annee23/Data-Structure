#include <iostream>
#include<string>
using namespace std;

struct Node {
    Node* next = NULL;
    int data = 0;
};
struct Queue {
    int count = 0;
    Node* head = NULL;
    Node* tail = NULL;
    void push(int x) {
        count++;
        Node* newN = new Node;
        newN->data = x;
        if (head == NULL)
        {
            head = newN;
            tail = newN;
        }
        else {
            tail->next = newN;
            tail = newN;
        }
    }
    int pop() {
        if (head == NULL)
            return -1;
        Node* temp = head;
        int tempi = head->data;
        
        if (head->next == NULL)
            head = NULL;
        else {
            head = head->next;
            temp = NULL;
        }
        count--;
        return tempi;

    }
    int size() {
        return count;
    }
    bool empty() {
        return count == 0;
    }
    int front() {
        if (head == NULL)
            return -1;
        return head->data;
    }
    int back() {
        if (head == NULL)
            return -1;
        return tail->data;
    }
};
int main() {
    int N;
    string s;
    cin >> N;

    Queue myQ;

    for (int i = 0; i < N; i++)
    {
        cin >> s;
        if (s == "push")
        {
            int n;
            cin >> n;
            myQ.push(n);
        }
        else if (s == "pop")
            cout << myQ.pop() << "\n";
        else if (s == "size")
            cout<<myQ.size() << "\n";
        else if (s == "empty")
            cout<<myQ.empty() << "\n";
        else if (s == "front")
           cout<< myQ.front() << "\n";
        else
            cout<<myQ.back() << "\n";
    }
    return 0;
}
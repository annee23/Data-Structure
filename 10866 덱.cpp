#include <iostream>
#include<string>
using namespace std;

struct Node {
    Node* next = NULL;
    Node* pre = NULL;
    int data = 0;
};
struct Deque {
    int count = 0;
    Node* front = NULL;
    Node* back = NULL;
    void push_front(int x) {
        count++;
        Node* newN = new Node;
        newN->data = x;
        if (front == NULL)
        {
            front = newN;
            back = newN;
        }
        else
        {
            front->pre = newN;
            newN->next = front;
            front = newN;
        }
    }
    void push_back(int x) {
        count++;
        Node* newN = new Node;
        newN->data = x;
        if (back == NULL)
        {
            front = newN;
            back = newN;
        }
        else
        {
            back->next = newN;
            newN->pre = back;
            back = newN;
        }

    }
    int pop_front() {
        if (front == NULL)
            return -1;
        count--;
        Node* tempN = front;
        int temp = front->data;
        if (count == 0)
        {
            front = NULL;
            back = NULL;
            return temp;
        }
        if (front->next != NULL) {
            front = front->next;
            front->pre = NULL;
            delete tempN;

        }
        else {
            delete tempN;
            front = NULL;
        }
        return temp;
    }
    int pop_back() {
        if (back == NULL)
            return -1;
        count--;
        int temp = back->data;
        Node* tempN = back;
        if (count == 0)
        {
            front = NULL;
            back = NULL;
            return temp;
        }
        if (back->pre != NULL)
        {
            back = back->pre;
            back->next = NULL;
            delete tempN;

        }
        else {
            delete tempN;
            back = NULL;
        }
        return temp;
    }
    int size() {
        return count;
    }
    bool empty() {
        return count == 0;
    }
    int Front() {
        if (front == NULL)
            return -1;
        return front->data;
    }
    int Back() {
        if (back == NULL)
            return -1;
        return back->data;
    }  
    };
    int main() {
        int N;
        string s;
        cin >> N;

        Deque myD;

        for (int i = 0; i < N; i++)
        {
            cin >> s;
            if (s == "push_front")
            {
                int n;
                cin >> n;
                myD.push_front(n);
            }
            else if (s == "push_back")
            {
                int n;
                cin >> n;
                myD.push_back(n);
            }
            else if (s == "pop_front")
                cout << myD.pop_front() << "\n";
            else if (s == "pop_back")
                cout << myD.pop_back() << "\n";
            else if (s == "size")
                cout << myD.size() << "\n";
            else if (s == "empty")
                cout << myD.empty() << "\n";
            else if (s == "front")
                cout << myD.Front() << "\n";
            else
                cout << myD.Back() << "\n";
        }
        return 0;
    }
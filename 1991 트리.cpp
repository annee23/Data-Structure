#include <iostream>
#include<string>
#include <vector>

using namespace std;

struct Node {
    Node* LC = NULL;
    Node* RC = NULL;
    char data = 0;
};
void visitpre(Node* N) {
    cout << N->data;
    if(N->LC!=NULL)
        visitpre(N->LC);
    if(N->RC!=NULL)
        visitpre(N->RC);
}
void visitin(Node* N) {
    if (N->LC != NULL)
        visitin(N->LC);
    cout << N->data;
    if (N->RC != NULL)
        visitin(N->RC);
}
void visitpost(Node* N) {
    if (N->LC != NULL)
        visitpost(N->LC);
    if (N->RC != NULL)
        visitpost(N->RC);
    cout << N->data;
}

int main() {
    int N;
    cin >> N;

    vector<Node*> v;

    for (int i = 0; i < N; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        if (i == 0)
        {
            Node* newN = new Node;
            newN->data = a;
            v.push_back(newN);
        }
        for (int j = 0; j < i; j++) {
            if (v[j]->LC != NULL && v[j]->LC->data == a) {
                v.push_back(v[j]->LC);
                break;
            }
            else if (v[j]->RC!= NULL && v[j]->RC->data == a) {
                v.push_back(v[j]->RC);
                break;
            }
            else if(j==i-1) {
                Node* newN = new Node;
                newN->data = a;
                v.push_back(newN);
            }

        }
        if (b != '.') {
            Node* newL = new Node;
            newL->data = b;
            v[i]->LC = newL;
        }
        if (c != '.')
        {
            Node* newR = new Node;
            newR->data = c;
            v[i]->RC = newR;
        }
    }

    visitpre(v[0]);
    cout << "\n";
    visitin(v[0]);
    cout << "\n";
    visitpost(v[0]);
    cout << "\n";

    return 0;

}



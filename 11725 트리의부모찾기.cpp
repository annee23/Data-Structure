#include<iostream>
#include<vector>
using namespace std;

vector<int> v[100001];
bool b[100001] = { false, };
int pa[100001];

void visit(int i)
{
    b[i] = true;
    for (int j = 0; j < v[i].size(); j++) {
        int temp = v[i][j];
        if (!b[temp])
        {
           pa[temp] = i;
           visit(temp);
        }
    }
}
int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visit(1);
    for(int i=2;i<=N;i++)
        cout << pa[i] << "\n";

    return 0;
}
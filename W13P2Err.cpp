#include <iostream>
#include <vector>
#include <string>
#define UNVIS 0
#define VIS 1
#define BACK 2
using namespace std;
struct ed {
	int S = 0; int D = 0;
};
vector<vector<int>> graph(2001);	//연결 메트릭스
string wei[2001][2001];		//U확인용
bool edges[2001][2001] = { 0, };	//edge 유무 확인용
int vertices[2001] = { 0, };		//vertex 정보저장
bool visited[2001];		//vertex visit 유무
vector<ed*> edL;
int main() {
	int N, M, K, temp, S, D;
	string U;
	cin >> N >> M >> K;
	int Vc = 0, Ec = 0;
	while (N--) {
		cin >> temp;
		vertices[temp] = temp;
		Vc++;
	}
	while (M--)
	{
		cin >> S >> D >> U;
		if (edges[S][D] == 0) {
			graph[S].push_back(D);
			graph[D].push_back(S);
			edges[S][D] = edges[D][S] = 1;
			wei[S][D] = wei[D][S] = U;
			ed* newe = new ed;
			//ed* newE = new ed;
			newe->S =S;
			newe->D = D;
			edL.push_back(newe);
			//edL.push_back(newE);
			Ec++;
		}
		else cout << -1 << endl;
	} 
	cout << Vc << " " << Ec << endl;
	while (K--) 
	{
		cin >> temp;
		if (vertices[temp] == 0)
			cout << -1 << endl;
		else {
			int t = graph[temp].size();
			for (int i = t - 1; i >= 0; i--) {
				edges[temp][i] = edges[i][temp] = 0;
				wei[S][D] = wei[D][S] = "";
				graph[temp].pop_back();
			}
			t = edL.size();
			for (int i = 0; i < t; i++)
			{
				if (edL[i]->S == temp || edL[i]->D == temp)
				{
					edL[i] = NULL; Ec--;
				}
			}
			vertices[temp] = 0;
			cout << Ec << " ";
			for (int i = 0; i < edL.size(); i++) {
				if(edL[i]!=NULL)
					cout << wei[edL[i]->S][edL[i]->D] << " ";
			}cout << endl;
		}
	}
	return 0;
}
#include<iostream>
#include<vector>
#include<string>
#define NO_VER -1
#define VISITED 1
#define UNVISITED 3
#define BACK 2
using namespace std;
vector<vector<int>>graph(20001);
vector<int> vertices;
int edge[20001][20001];
int visit[20001];
struct ed {
	int s = 0, d = 0;
	string str;
};
vector<ed*> Str;
void DFS(int V) {
	if (graph[V].size() == 0)
		return;
	cout << V << " ";
	visit[V] = VISITED;
	for (int i = 0; i < graph[V].size(); i++)
	{
		if (edge[V][graph[V][i]] == UNVISITED)
		{
			if (visit[graph[V][i]] == UNVISITED)
			{
				edge[V][graph[V][i]] = edge[graph[V][i]][V] = VISITED;
				DFS(graph[V][i]);
			}
			else edge[V][graph[V][i]] = edge[graph[V][i]][V] = BACK;
		}
	}
}
int main() {
	int N, M, A, temp, S, D;
	string U;
	cin >> N >> M >> A;
	while (N--) {
		cin >> temp;
		vertices.push_back(temp);
		visit[temp] = UNVISITED;
	}
	while (M--) {
		cin >> S >> D >> U;
		if (edge[S][D] != 0)
			cout << -1 << endl;
		else {
			edge[S][D] = edge[D][S] = UNVISITED;
			graph[S].push_back(D);
			graph[D].push_back(S);
			ed* newe = new ed;
			newe->s = S;
			newe->d = D;
			newe->str = U;
			Str.push_back(newe);
		}
	}
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i] == A)
			temp = i;
	}
	for (int i = temp; i < vertices.size(); i++) {
		if (visit[vertices[i]] == 0)
			DFS(vertices[i]);
	}
	for (int i = 0; i < temp; i++) {
		if (visit[vertices[i]] == 0)
			DFS(vertices[i]);
	}
	return 0;
}
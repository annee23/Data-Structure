#include<iostream>
#include<vector>
#define UNVISITED 0;
#define VISITED 1;
#define BACK 2;
using namespace std;
struct Vrt {
	int idx = -1;
	char data = '0';
	int flag_V = UNVISITED;
};
//struct Edg {
//	Vrt* S = NULL;
//	Vrt* D = NULL;
//	int flag_E = UNVISITED;
//};
vector<Vrt*> V;
//vector<Edg*> E;
vector<vector<int>> Matrix(500, vector<int>(500, -1));
void DFS(Vrt* it) {
	it->flag_V = 1;
	for (int i = 0; i < 501; i++)
	{
		if (Matrix[it->idx][i] != -1)
		{
			if(Matrix[it->idx][i])
		}
	}
}
int main() {
	int N, M, K, I, S, D;
	char C;
	cin >> N >> M >> K;
	for(int i=0;i<N;i++)
	{
		cin >> I >> C;
		Vrt* newV = new Vrt;
		newV->data = C;
		newV->idx = I;
		V.push_back(newV);
	}
	while (M--) {
		cin >> S >> D;
		Matrix[S][D] = Matrix[D][S] = UNVISITED;
	}
	for (int i = 0; i < N; i++)
		if(V[i]->flag_V==0)
			DFS(V[i]);
	return 0;
}

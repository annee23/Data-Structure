#include <iostream>
#include <vector>
#include<string>
using namespace std;

struct Vrt {
	int idx = 0;
	int name = 0;
};
struct Edg {
	Vrt* S = NULL;
	Vrt* D = NULL;
	string wgt;
};
vector<Vrt*>v;
vector<vector<Edg*> >e;
vector<Edg*> E;
Vrt* findV(int F) {
	Vrt* it = NULL;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->name == F)
		{
			it = v[i];
			break;
		}
	}
	return it;
}
int main() {
	int N, M, I, S, D, K, L;
	string U;
	int countE = 0;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		vector<Edg*>c{ NULL, };
		c.resize(N);
		e.push_back(c);
	}
	for(int i=0;i<N;i++) {
		cin >> I;
		Vrt* newV = new Vrt;
		newV->idx = i;
		newV->name = I;
		v.push_back(newV);
	}
	while (M--) {
		cin >> S >> D >> U;
		Edg* newE = new Edg;
		newE->S = findV(S);
		newE->D = findV(D);
		newE->wgt = U;
		E.push_back(newE);
		if (e[newE->S->idx][newE->D->idx] != NULL)
			cout << 0 << endl;
		else
		{
			e[newE->S->idx][newE->D->idx] = newE;
			e[newE->D->idx][newE->S->idx] = newE;
			countE++;
		}
	}
	while (K--) {
		cin >> L;
		bool find = false;
		for (int i = 0; i < v.size(); i++) {
			if (v[i]->name == L)
			{
				find = true;
				for (int j = 0; j < N; j++)
				{
					if (e[v[i]->idx][j] != NULL)
					{
						e[v[i]->idx][j]->wgt = "GONE!";
						e[v[i]->idx][j] = NULL;
						e[j][v[i]->idx] = NULL;

						countE--;
					}
				}
				v.erase(v.begin()+i);
				N--;
			}
		}
		if (!find)
			cout << -1 << endl;
		else
		{
			for (int i = 0; i < E.size(); i++)
			{
				if (E[i]->wgt=="GONE!")
					continue;
				else
					cout << E[i]->wgt << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
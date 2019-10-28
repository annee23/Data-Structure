#include<iostream>
#include<vector>
#include<cstdlib>
//11286
using namespace std;
int main() {
	int N, t;
	int swap;
	cin >> N;
	vector<int>heap;
	heap.push_back(0);
	while (N--) {
		cin >> t;
		if(t==0&&heap.size() == 1)
			cout << 0 << "\n";
		else if (t == 0) {//downheap
			cout << heap[1] << "\n";
			heap[1] = heap[heap.size() - 1];
			heap.pop_back();
			for (int i = 1; i * 2 < heap.size();) {
				if (i * 2 + 1 == heap.size()) {
					if (abs(heap[i * 2]) < abs(heap[i]) || ((abs(heap[i * 2]) == abs(heap[i])) && (heap[i * 2] < heap[i])))
					{
						swap = heap[i];
						heap[i] = heap[i * 2];
						heap[i * 2] = swap;
						break;
					}
					else break;
				}
				else if (abs(heap[i * 2]) == abs(heap[i * 2 + 1])&&( abs(heap[i])>abs(heap[i*2])) ){
					if(heap[i*2]<=heap[i*2+1]) {
						swap = heap[i];
						heap[i] = heap[i * 2];
						heap[i * 2] = swap;
						i = i * 2;
					}
					else
					{
						swap = heap[i];
						heap[i] = heap[i * 2+1];
						heap[i * 2+1] = swap;
						i = i * 2+1;
					}
				}
				else if (abs(heap[i * 2]) == abs(heap[i * 2 + 1]) && (abs(heap[i]) == abs(heap[i * 2]))) {
					if (heap[i * 2] <= heap[i * 2 + 1] && heap[i * 2] < heap[i]) {
						swap = heap[i];
						heap[i] = heap[i * 2];
						heap[i * 2] = swap;
						i = i * 2;
					}
					else if (heap[i * 2] > heap[i * 2 + 1] && heap[i * 2 + 1] < heap[i])
					{
						swap = heap[i];
						heap[i] = heap[i * 2 + 1];
						heap[i * 2 + 1] = swap;
						i = i * 2 + 1;
					}
					else break;
				}
				else if (abs(heap[i*2])<abs(heap[i*2+1])&& (abs(heap[i * 2]) < abs(heap[i]) || ((abs(heap[i * 2]) == abs(heap[i])) && (heap[i * 2] < heap[i])))) {
					swap = heap[i];
					heap[i] = heap[i * 2];
					heap[i * 2] = swap;
					i=i*2;
					
				}
				else if (abs(heap[i * 2]) > abs(heap[i * 2 + 1]) && (abs(heap[i * 2+1]) < abs(heap[i]) || ((abs(heap[i * 2+1]) == abs(heap[i])) && (heap[i * 2+1] < heap[i])))) {
					swap = heap[i];
					heap[i] = heap[i * 2+1];
					heap[i * 2+1] = swap;
					i = i * 2+1;				
				}
				else
					break;
			}
		}
		else {//upheap
			heap.push_back(t);
			for (int i =heap.size()-1;i>0; i/=2)
			{
				if (abs(heap[i]) == abs(heap[i / 2]))
				{
					if (heap[i] < heap[i / 2])
					{
						swap = heap[i];
						heap[i] = heap[i / 2];
						heap[i / 2] = swap;
					}
					else
						break;
				}
				else if (abs(heap[i]) < abs(heap[i / 2]))
				{
					swap = heap[i];
					heap[i] = heap[i / 2];
					heap[i / 2] = swap;
				}
				else
					break;
			}
		}
	}
	return 0;
}
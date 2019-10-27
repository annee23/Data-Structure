#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int>heap;
	heap.push_back(0);
	while (N--) {
		int num;
		cin >> num;
		heap.push_back(num);
		for (int i = heap.size()-1; i>0; i=i/2)
		{
			if (heap[i] < heap[i / 2])
			{
				int temp = heap[i];
				heap[i]= heap[i / 2];
				heap[i / 2] = temp;
			}//upheap
		}
	}
	for (int i = 1; i < heap.size(); i++)
		cout << heap[i] << " ";
	cout << endl;
	return 0;
}
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

	vector<int> sort;
	while (1) {
		sort.push_back(heap[1]);
		heap[1] = heap[heap.size() - 1];
		heap.pop_back();
		if (heap.size() == 1)
			break;
		for (int i = 1; i * 2 <= heap.size() - 1;) {	//downheap
			if (i * 2 + 1 == heap.size()) {		//자식이 왼쪽만 있을때
				if (heap[i] > heap[i * 2]) {
					int temp = heap[i * 2];
					heap[i * 2] = heap[i];
					heap[i] = temp;
					break;
				}
				else
					break;
			}
			else if (heap[i] > heap[i * 2] && heap[i * 2] < heap[i * 2 + 1]) //왼쪽자식 더 작을때
			{

				int temp = heap[i * 2];
				heap[i * 2] = heap[i];
				heap[i] = temp;
				i = i * 2;
			}
			else if (heap[i] > heap[i * 2 + 1] && heap[i * 2] > heap[i * 2 + 1]) { //오른쪽자식 더 작을때
				int temp = heap[i * 2 + 1];
				heap[i * 2 + 1] = heap[i];
				heap[i] = temp;
				i = i * 2 + 1;
			}
			else
				break;		//부모가 가장 작을때
		}
	}
	for (auto a : sort)
		cout << a << " ";
	cout << endl;
	return 0;
}
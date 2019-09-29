#include<iostream>


using namespace std;
int sum = 0;

int mario(int arr[],int n)
{
  
        sum += arr[n];
        if ((100 - sum) > (sum + arr[n + 1] - 100))
            return mario(arr, n + 1);
        else if ((100 - sum) == (sum + arr[n + 1] - 100))
            return sum + arr[n + 1];
        else
            return sum;
    
}
int main() {
    int arr[10] = { 0, };
    for (int i = 0; i < 10; i++)
    {
        int a = 0;
        cin >> a;
        arr[i] = a;

    }

    int num=mario(arr, 0);
    cout << num;
    return 0;
    
}

#include<iostream>
using namespace std;
int sum = 0;

int main() {
    int arr[10] = { 0, };
    for (int i = 0; i < 10; i++)
    {
        int a = 0;
        cin >> a;
        arr[i] = a;

    }
    for (int i = 0; i < 10; i++) {
        sum += arr[i];
        if ((100 - sum) == (sum + arr[i + 1] - 100))
        {
            sum += arr[i + 1];
            break;
        }
        else if((100 - sum)<(sum + arr[i + 1] - 100))
            break;
    }

    cout << sum;
    return 0;

}

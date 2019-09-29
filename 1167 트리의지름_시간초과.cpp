#include<iostream>
#include <vector>
#include<cstring>
using namespace std;

int dis = 0;
vector<int> v[100000];
bool arr [100000] = { false, };
struct ret {
    int distance = 0;
    int final = 0;
};
ret visit(int in) {
    int j = 1;
    while (!arr[in]) {
        if (v[in][j] == -1)
        {
            //memset(arr, false, sizeof(arr));
           // arr[in] = true;
            ret r;
            r.distance = dis;
            r.final = in;
            return r;

        }
        if (!arr[v[in][j]])
        {
            dis += v[in][j + 1];
            arr[in] = true;
            return visit(v[in][j]);
        }
        else
            j += 2;
    }
}
int main() {
    int V;
    cin >> V;
   
    for (int i = 1; i <=V; i++) {
        int t = 0;
        while (t != -1) {
            cin >> t;
            v[i].push_back(t);
        }
    }
 
    int max = 0,temp = 0;
   
    for (int j = 1; j <=V; j++) {
        vector<int> snwjr;
        for (int i = 0; i < 2; i++) {
            dis = 0;
            ret rr = visit(j);
            temp = rr.distance;
           // snwjr.push_back(rr.final);
           // memset(arr, false, sizeof(arr));
          //  for (auto a : snwjr)
            //    arr[a] = true;
            if (max < temp)
                max = temp;
        }
        memset(arr, false, sizeof(arr));
    }
    cout << max;
    return 0;

}

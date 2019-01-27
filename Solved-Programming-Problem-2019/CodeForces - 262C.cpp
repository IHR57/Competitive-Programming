#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

const int inf = 1<<28;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, q, n, arr[MAX];

    cin>>m;

    int Min = inf;
    for(int i = 0; i < m; i++){
        cin>>q;
        if(q < Min){
            Min = q;
        }
    }

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr, arr + n);

    int cost = 0;
    for(int i = n - 1; i >= 0; ){
        int j;
        for(j = i; j > max(-1, (i - Min)); j--){
            cost += arr[j];
        }
        i = j - 2;
    }

    cout<<cost<<endl;

    return 0;
}

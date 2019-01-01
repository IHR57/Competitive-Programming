#include <bits/stdc++.h>
#define MAX 50005
using namespace std;

int arr[MAX][6];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, total = 0, value;

    cin>>m>>n;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin>>arr[i][j];
        }
    }

    int finish[MAX] = {0};

    for(int i = 1; i <= n; i++){
        int t = 0;
        for(int j = 1; j <= m; j++){
            int temp = max(t, finish[j]);
            finish[j] = temp + arr[j][i];
            t = finish[j];
        }
    }

    for(int i = 1; i <= m; i++){
        cout<<finish[i]<<" ";
    }
    cout<<endl;

    return 0;
}

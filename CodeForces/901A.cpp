// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, x, y;
    int visited[MAX] = {0};

    cin>>n>>m;

    m = 2 * m;

    for(int i = 0; i < n; i++){
        cin>>x>>y;
        for(int j = 2 * x; j <= 2 * y; j++)
            visited[j] = 1;
    }

    for(int i = 0; i <= m; i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;

    return 0;
}

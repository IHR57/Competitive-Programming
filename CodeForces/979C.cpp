// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

vector<int> graph[3*MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x, y, u, v;

    cin>>n>>x>>y;

    int flag = 0;

    for(int i = 0; i < n - 1; i++){
        cin>>u>>v;
        if((u == x && v == y) || (u == y && v == x)){
            flag = 1;
        }
    }

    if(flag){
        cout<<(n - 1) * 2<<endl;
    }
    else{
        cout<<(n - 1) * 2 + 1<<endl;
    }
    return 0;
}

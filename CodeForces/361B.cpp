#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, visited[MAX], temp[MAX];

    cin>>n>>k;

    if(k >= n){
        cout<<-1<<endl;
        return 0;
    }

    memset(visited, 0, sizeof(visited));
    visited[0] = 1;

    if(n % 2 == 0){
        int t = (k % 2 == 0) ? 1 : 2;
        if(t == 2)  visited[1] = 1, temp[1] = 1;
        for(int i = t; i <= n - k; i++){
            if(!visited[i-1])   temp[i] = i - 1, visited[i-1] = 1;
            else if(!visited[i+1]) temp[i] =  i + 1, visited[i+1] = 1;
        }
        for(int i = n - k + 1; i <= n; i++){
            temp[i] = i;
        }

        for(int i = 1; i <= n; i++)
            cout<<temp[i]<<" ";
        cout<<endl;
    }
    else if(n % 2 != 0){
        int t = (k % 2 == 0) ? 2 : 1;
        if(t == 2)  visited[1] = 1, temp[1] = 1;
        for(int i = t; i <= n - k; i++){
            if(!visited[i-1])   temp[i] = i - 1, visited[i-1] = 1;
            else if(!visited[i+1]) temp[i] =  i + 1, visited[i+1] = 1;
        }
        for(int i = n - k + 1; i <= n; i++){
            temp[i] = i;
        }

        for(int i = 1; i <= n; i++)
            cout<<temp[i]<<" ";
        cout<<endl;
    }

    return 0;
}

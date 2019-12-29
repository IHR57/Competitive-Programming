//Problem ID: CodeForces - 995B (Suit and Tie)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 18/02/19
#include <bits/stdc++.h>
#define MAX 205
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int vis[MAX] = {0}, dist[MAX], n, arr[MAX], temp[MAX];

    cin>>n;

    for(int i = 0; i < 2 * n; i++){
        cin>>arr[i];
        if(!vis[arr[i]]){
            dist[arr[i]] = i;
            vis[arr[i]] = 1;
        }
        else{
            arr[i] = arr[i] + n;
            dist[arr[i]] = i;
        }
    }

    memset(vis, 0, sizeof(vis));

    int cnt = 0;
    for(int i = 0; i < 2 * n - 1; i += 2){
        if(arr[i+1] == arr[i] + n)
            continue;
        cnt += dist[arr[i]+n] - dist[arr[i]] - 1;
        int idx = dist[arr[i]+n];
        memset(temp, 0, sizeof(temp));
        for(int j = i + 2; j <= idx; j++){
            temp[j] = arr[j-1];
        }
        arr[i+1] = arr[i] + n;
        for(int j = i + 2; j <= idx; j++){
            arr[j] = temp[j];
            dist[arr[j]] = j;
        }
    }

    cout<<cnt<<endl;

    return 0;
}

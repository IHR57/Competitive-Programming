#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int visited[MAX], arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, cnt = 0;

    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    while(1){
        memset(visited, 0, sizeof(visited));
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(!visited[arr[i]] && arr[i] < k){
                visited[arr[i]] = 1;
                arr[i]++;
                flag = false;
            }
        }
        cnt++;
        if(flag)
            break;
    }

    cout<<cnt-1<<endl;

    return 0;
}

#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, arr[MAX];

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == i)
            ans++;
    }

    if(ans == n){
        cout<<ans<<endl;
        return 0;
    }

    int flag = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != i){
            if(arr[arr[i]] == i){
                flag = 1;
                break;
            }
        }
    }

    if(flag){
        ans += 2;
        cout<<ans<<endl;
    }
    else{
        ans += 1;
        cout<<ans<<endl;
    }

    return 0;
}

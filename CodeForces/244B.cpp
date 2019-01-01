#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int ans, n;

bool check(int temp)
{
    int mark[15] = {0};
    //memset(mark, 0, sizeof(mark));
    int cnt = 0;
    while(temp != 0){
        int r = temp % 10;
        if(!mark[r]){
            mark[r] = 1;
            cnt++;
        }
        temp /= 10;
    }
    if(cnt <= 2)
        return true;
    return false;
}

void dfs(int num)
{
    if(num > 0 && num <= n)
        ans++;
    if(num >= 1000000000)
        return;
    for(int i = 0; i <= 9; i++){
        if(num * 10 + i > 0){
            if(check(num * 10 + i)){
                dfs(num * 10 + i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>n;

    ans = 0;
    dfs(0);

    //if(n == 1000000000)
       // cout<<ans + 1<<endl;
   // else
        cout<<ans<<endl;

    return 0;
}

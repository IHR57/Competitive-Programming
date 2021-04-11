#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
using namespace std;
 
typedef long long ll;
 
ll dp[MAX];
int n, phi[MAX], mark[MAX];
 
void sievephi()
{
    for(int i = 1; i <= n; i++)
        phi[i] = i;
 
    phi[1] = 1;
    mark[1] = 1;
 
    for(int i = 2; i <= n; i++){
        if(!mark[i]){
            for(int j = i; j <= n; j += i){
                mark[j] = 1;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m;
    cin>>n>>m;
    
    sievephi();
    
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + phi[i];
    }
    
    //cout<<dp[1000]<<endl;
    
    if(m < n - 1 || m > dp[n]){
        cout<<"Impossible"<<endl;
        return 0;
    }
    
    int cnt = m;
    cout<<"Possible"<<endl;
    for(int i = 1; i <= n - 1; i++){
        cout<<i<<" "<<i + 1<<endl;
        cnt--;
    }
    if(cnt > 0){
        for(int i = 3; i <= n; i++){
            cout<<1<<" "<<i<<endl;
            cnt--;
            if(cnt == 0)
                return 0;
        }
    }
    if(cnt > 0){
        for(int i = 2; i <= n; i++){
            for(int j = i + 2; j <= n; j++){
                if(__gcd(i, j) == 1){
                    cout<<i<<" "<<j<<endl;
                    cnt--;
                    if(cnt == 0)
                        return 0;
                }
            }
        }
    }
    
    return 0;
}
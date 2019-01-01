#include <iostream>
using namespace std;

int main()
{
    int test, caseno=1, n, result;

    cin>>test;

    while(test--){
        long long int dp[10005], n, i;
        for(i=0; i<6; i++){
            cin>>dp[i];
        }
        cin>>n;
        for(i=6; i<=n; i++){
            dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%10000007;
        }
        cout<<"Case "<<caseno++<<": "<<dp[n]%10000007<<endl;
    }

    return 0;
}

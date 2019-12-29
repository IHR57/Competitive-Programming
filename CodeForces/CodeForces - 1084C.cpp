//Problem ID: CodeForces - 1084C (The Fair Nut and String)
//Programmer: IQBAL HOSSAIN     Description: DP, Combinatorics
//Date: 10/02/19
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000007
using namespace std;

typedef long long ll;

string str;
ll temp[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>str;

    int len = (int) str.length();

    ll ans = 0, idx = -1;
    for(int i = 0; i < len; i++){
        if(str[i] == 'a'){
            ans++;
            if(idx >= 0){
                ans = (ans + temp[idx]) % MOD;
            }
        }
        else if(str[i] == 'b'){
            idx = i;
            temp[i] = ans;
        }
    }

    cout<<ans % MOD<<endl;

    return 0;
}

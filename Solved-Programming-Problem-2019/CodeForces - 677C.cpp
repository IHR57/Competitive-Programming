//Problem ID: CodeForces - 677C (Vanya and Label)
//Programmer: IQBAL HOSSAIN     Description: Implementation/MATH
//Date: 31/03/19
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000007
using namespace std;

typedef long long ll;
map<char, int> mp;
string str;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string charSet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_";
    for(int i = 0; i < 64; i++)
        mp[charSet[i]] = i;

    cin>>str;
    int len = (int) str.length();

    ll res = 1;
    for(int i = 0; i < len; i++){
        int temp = mp[str[i]];
        for(int j = 0; j < 6; j++){
            if((temp & (1 << j)) == 0){
                res = (res * 1LL * 3) % MOD;
            }
        }
    }

    cout<<res<<endl;

    return 0;
}

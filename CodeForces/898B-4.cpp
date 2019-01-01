// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int k, p;

    cin>>k>>p;
    ll temp, j;
    ll result = 0;

    for(int i = 1; i <= k; i++){
        j = i;
        temp = i;
        while(j > 0){
            temp = temp *10 + j % 10;
            j /= 10;
        }
        result = (result % p + temp % p) % p;
        //cout<<result<<endl;
    }

    result = result % p;
    cout<<result<<endl;

    return 0;
}

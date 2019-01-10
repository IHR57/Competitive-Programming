//Problem ID: CodeForces - 365C (Matrix)
//Programmer: IQBAL HOSSAIN     Description: Mathematics
//Date: 09/01/19
#include <bits/stdc++.h>
#define MAX 4005
using namespace std;

typedef long long ll;

int counter[MAX*10];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a;
    char str[MAX];

    cin>>a;
    cin>>str;

    int cs[MAX], temp[MAX], len = strlen(str);
    cs[0] = 0;

    for(int i = 0; i < len; i++){
        temp[i+1] = str[i] - 48;
    }

    for(int i = 1; i <= len; i++){
        cs[i] = cs[i-1] + temp[i];
    }

    for(int i = 1; i <= len; i++){
        for(int j = i; j <= len; j++){
            counter[cs[j] - cs[i-1]]++;
        }
    }

    ll ans = 0;
    if(a == 0){
        for(int i = 0; i < 37000; i++){
            ans += ((ll) counter[0] * (ll) counter[i]);
        }
    }

    for(int i = 1; i <= 37000; i++){
        if(a % i == 0){
            if((a / i) >= 0 && (a / i) <= 37000){
                ans += ((ll) counter[i] * (ll) counter[a/i]);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}

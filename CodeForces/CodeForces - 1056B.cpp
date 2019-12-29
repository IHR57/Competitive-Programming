//Problem ID: CodeForces - 1056B (Divide Candies)
//Programmer: IQBAL HOSSAIN     Description: Modular Arithmetic
//Date: 15/04/19
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

typedef long long ll;

ll counter[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;

    int div = n / m, rem = n % m;
    for(int i = 1; i <= m; i++){
        int temp = (i * i) % m;
        counter[temp]++;
    }
    for(int i = 0; i < m; i++){
        counter[i] = counter[i] * div;
    }

    for(int i = 1; i <= rem; i++){
        int temp = (i * i) % m;
        counter[temp]++;
    }

    ll ans = counter[0] * counter[0];

    for(int i = 1; i < m; i++){
        ans += (counter[i] * counter[m - i]);
    }

    cout<<ans<<endl;

    return 0;
}

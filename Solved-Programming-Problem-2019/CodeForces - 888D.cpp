//Problem ID: CodeForces - 888D (Almost Identity Permutations)
//Programmer: IQBAL HOSSAIN     Description: Mathematics/Combinatorics
//Date: 07/05/19
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

typedef long long ll;

ll d[MAX], ncr[MAX][5];

void precal()
{
    ncr[0][0] = 1, ncr[1][1] = 1, ncr[1][0] = 1;
    ncr[2][0] = 1, ncr[2][1] = 2, ncr[2][2] = 1;
    ncr[3][0] = 1, ncr[3][1] = 3, ncr[3][2] = 3, ncr[3][3] = 1;
    for(int i = 4; i < MAX; i++){
        for(int j = 0; j <= 4; j++){
            if(j == 0 || j == i)
                ncr[i][j] = 1;
            else
                ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    precal();
    int n, k;

    cin>>n>>k;

    d[0] = 1, d[1] = 0, d[2] = 1, d[3] = 2, d[4] = 9;

    ll ans = 0;
    for(int i = 0; i <= k; i++){
        ans += (ncr[n][i] * d[i]);
    }

    cout<<ans<<endl;

    return 0;
}

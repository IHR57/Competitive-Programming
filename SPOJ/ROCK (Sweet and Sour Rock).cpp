#include <bits/stdc++.h>
#define MAX 205
#define INF 1<<28
using namespace std;

int m[MAX][MAX], cs[MAX];
char str[MAX];

void solve(int n)
{
    int q;
    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = -INF;
            for(int k = i; k <= j - 1; k++){
                q = m[i][k] + m[k+1][j];
                if(q > m[i][j]){
                    m[i][j] = q;
                }
            }
            int ones, zeros;
            if((str[i-1] == '1')){
                ones = cs[j] - cs[i] + 1;
                zeros = l - ones;
            }
            else{
                ones = cs[j] - cs[i];
                zeros = l - ones;
            }
            if(ones > zeros)
                m[i][j] = l;
        }
    }
}

int main()
{
    int test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        memset(cs, 0, sizeof(0));
        scanf("%s", str);
        for(int i = 0; i < n; i++){
            (str[i] == '1') ? m[i+1][i+1] = 1 : m[i+1][i+1] = 0;
            (str[i] == '1') ? cs[i+1] = cs[i] + 1 : cs[i+1] = cs[i];        //number of 1's
        }

        solve(n);
        //cout<<cs[n]<<endl;
        printf("%d\n", m[1][n]);
    }

    return 0;
}

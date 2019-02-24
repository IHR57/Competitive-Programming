//Problem ID: LightOJ - 1233 (Coin Change III)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 19/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1233
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int a[MAX], c[MAX], visited[MAX*1000], cnt[MAX*1000];

int main()
{
    int test, caseno = 1, n, m;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);

        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &c[i]);
        }

        visited[0] = 1;
        for(int i = 0; i < n; i++){
            memset(cnt, 0, sizeof(cnt));
            for(int j = a[i]; j <= m; j++){
                if(!visited[j]){
                    if(cnt[j - a[i]] < c[i]){
                        visited[j] |= visited[j - a[i]];
                        cnt[j] = cnt[j - a[i]] + 1;
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= m; i++){
            if(visited[i])
                ans++;
        }

        printf("Case %d: %d\n", caseno++, ans);
    }

    return 0;
}

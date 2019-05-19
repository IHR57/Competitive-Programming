//Problem ID: HackerRank - Game of Two Stacks
//Programmer: IQBAL HOSSAIN     Description: Stacks
//Date: 19/05/19
//Problem Link: https://www.hackerrank.com/challenges/game-of-two-stacks/problem
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int a[MAX], b[MAX];
ll cs[MAX];

int main()
{
    int test, n, m;
    ll x;
    scanf("%d", &test);

    while(test--){
        scanf("%d %d %lld", &n, &m, &x);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        cs[0] = 0;
        for(int i = 1; i <= m; i++){
            scanf("%d", &b[i]);
            cs[i] = (ll) b[i] + cs[i-1];
        }
        int Max = upper_bound(cs + 1, cs + m + 1, x) - cs;
        Max--;
        ll sum = 0;
        for(int i = 1; i <= n; i++){
            sum += (ll) a[i];
            if(sum > x)
                break;
            int idx = upper_bound(cs + 1, cs + m + 1, x - sum) - cs;
            //cout<<idx - 1<<endl;
            Max = max(Max, i + idx - 1);
        }

        printf("%d\n", Max);

    }

    return 0;
}

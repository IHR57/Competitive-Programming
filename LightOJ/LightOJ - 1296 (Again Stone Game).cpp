//Problem ID: LightOJ - 1296 (Again Stone Game)
//Programmer: IQBAL HOSSAIN     Description: Game Theory (Grundy Numbers)
//Date: 11/05/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int solve(int n)
{
    if(n % 2 == 0)
        return n / 2;
    if(n == 1 || n == 3)
        return 0;
    return solve(n / 2);
}

int main()
{
    int test, caseno = 1, n, m;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &m);
            if(m == 1 || m == 3)
                continue;
            if(m % 2 == 0){
                ans ^= (m / 2);
            }
            else{
                ans ^= solve(m);
            }
        }
        printf("Case %d: ", caseno++);
        (ans) ? printf("Alice\n") : printf("Bob\n");
    }

    return 0;
}

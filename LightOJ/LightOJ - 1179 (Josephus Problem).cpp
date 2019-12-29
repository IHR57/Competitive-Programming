//Problem ID: LightOJ - 1179 (Josephus Problem)
//Programmer: IQBAL HOSSAIN     Description: Mathematics
//Date: 14/02/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int josephus(int n, int k)
{
    int res = 0;
    for(int i = 1; i <= n; i++){
        res = (res + k) % i;
    }

    return res + 1;
}

int main()
{
    int test, caseno = 1, n, k;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &k);
        printf("Case %d: %d\n", caseno++, josephus(n, k));
    }

    return 0;
}

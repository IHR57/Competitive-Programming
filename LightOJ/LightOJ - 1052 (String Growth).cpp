//Problem ID: LightOJ - 1052 (String Growth)
//Programmer: IQBAL HOSSAIN     Description: Matrix Expo
//Date: 05/02/19
#include <bits/stdc++.h>
#define MAX 5
#define MOD 1000000007
using namespace std;

typedef long long ll;

struct Matrix{
    ll v[MAX][MAX];
};

Matrix multiply(Matrix a, Matrix b)
{
    Matrix r;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            int sum = 0;
            for(int k = 0; k < 2; k++){
                sum = (sum + (a.v[i][k] * b.v[k][j]) % MOD) % MOD;
            }
            r.v[i][j] = sum % MOD;
        }
    }
    return r;
}

Matrix Power(Matrix mat, ll p)
{
    if(p == 1)
        return mat;
    if(p % 2 == 1){
        return multiply(mat, Power(mat, p - 1));
    }
    Matrix ret = Power(mat, p / 2);
    ret = multiply(ret, ret);

    return ret;
}

int main()
{
    ll n, x, m, y, k, test, caseno = 1;
    ll fib[65];

    fib[0] = fib[1] = 1;
    for(int i = 2; ; i++){
        int value = fib[i-1] + fib[i-2];
        if(value >= 1000000000)
            break;
        fib[i] = value;
    }

    scanf("%lld", &test);

    while(test--){
        scanf("%lld %lld %lld %lld %lld", &n, &x, &m, &y, &k);
        if(n > m){
            swap(n, m);
            swap(x, y);
        }

        printf("Case %d: ", caseno++);

//        cout<<fib[43]<<endl;
        if(n > 43 || m > 43){
            printf("Impossible\n");
            continue;
        }

        ll a1 = fib[n-1];
        ll b1 = fib[n];
        ll a2 = fib[m-1];
        ll b2 = fib[m];
        ll c1 = x, c2 = y;
        //cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<" "<<c1<<" "<<c2<<endl;
        ll d = (a1 * b2 - b1 * a2);
        ll tempx = (c1 * b2 - b1 * c2);
        ll tempy = (a1 * c2 - a2 * c1);

        if(d == 0 || (tempx / d < 0) || (tempx % d) != 0 || (tempy / d < 0) || (tempy % d) != 0){
            printf("Impossible\n");
            continue;
        }

        Matrix mat;
        memset(mat.v, 0, sizeof(mat.v));
        mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;

        mat = Power(mat, k);
        x = (tempx / d), y = (tempy / d);
        ll result = ((mat.v[1][0] * x) % MOD + (mat.v[0][0] * y) % MOD) % MOD;

        printf("%lld\n", result % MOD);
    }

    return 0;
}
/*
    if a1x + b1y = c1
       a2x + b2y = c2

       the matrix form will be:
       | a1 b1 | |x|   |c1|
       |       |*| | = |  |
       | a2 b2 | |y|   |c2|

       we can calculate x and y using cramer's rule

       x = (c1*b2 - c2*b1) / (a1*b2 - b1*a2)
       y = (a1*c2 - c2*a1) / (a1*b2 - b1*a2)

*/


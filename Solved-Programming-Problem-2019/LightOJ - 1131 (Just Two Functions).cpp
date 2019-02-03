//Problem ID: LightOJ - 1131 (Just Two Functions)
//Programmer: IQBAL HOSSAIN     Description: Matrix Exponentiation
//Date: 03/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1131
#include <bits/stdc++.h>
#define MAX 8
using namespace std;

typedef long long ll;
int MOD;

struct Matrix
{
    int v[MAX][MAX];
    int row, col;
};

Matrix multiply(Matrix a, Matrix b)
{
    Matrix r;
    r.row = a.row, r.col = b.col;
    for(int i = 0; i < r.row; i++){
        for(int j = 0; j < r.col; j++){
            int sum = 0;
            for(int k = 0; k < a.col; k++){
                sum = (sum + (a.v[i][k] * b.v[k][j]) % MOD) % MOD;
            }
            r.v[i][j] =  sum % MOD;
        }
    }

    return r;
}

Matrix Power(Matrix mat, int p)
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
    int test, caseno = 1, a1, a2, b1, b2, c1, c2, n, value, query;
    int f0, f1, f2, g0, g1, g2;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d", &a1, &b1, &c1);
        scanf("%d %d %d", &a2, &b2, &c2);
        scanf("%d %d %d", &f0, &f1, &f2);
        scanf("%d %d %d", &g0, &g1, &g2);
        scanf("%d", &MOD);

        Matrix mat, mul;
        mat.row  = mat.col = 6;
        mul.row = 6, mul.col = 1;
        memset(mat.v, 0, sizeof(mat.v));

        mat.v[0][0] = a1 % MOD, mat.v[0][1] = b1 % MOD, mat.v[0][5] = c1 % MOD;
        mat.v[3][2] = c2 % MOD, mat.v[3][3] = a2 % MOD, mat.v[3][4] = b2 % MOD;
        mat.v[1][0] = mat.v[2][1] = mat.v[4][3] = mat.v[5][4] = 1 % MOD;
        mul.v[0][0] = f2, mul.v[1][0] = f1, mul.v[2][0] = f0, mul.v[3][0] = g2, mul.v[4][0] = g1, mul.v[5][0] = g0;

        scanf("%d", &query);

        printf("Case %d:\n", caseno++);

        for(int i = 0; i < query; i++){
            scanf("%d", &n);
            if(n <= 2){
                if(n == 0)  printf("%d %d\n", f0 % MOD, g0 % MOD);
                if(n == 1)  printf("%d %d\n", f1 % MOD, g1 % MOD);
                if(n == 2)  printf("%d %d\n", f2 % MOD, g2 % MOD);
            }
            else{
                Matrix ret;
                ret.row = ret.col = 6;
                ret = Power(mat, n - 2);
                ret = multiply(ret, mul);

                int result1 = ret.v[0][0], result2 = ret.v[3][0];
                printf("%d %d\n", result1 % MOD, result2 % MOD);
            }
        }

    }

    return 0;
}

/*
Matrix will be like this:

    |a1 b1  0  0  0  c1|  | f(n-1) |    | f(n) |
    | 1  0  0  0  0  0 |  | f(n-2) |    |f(n-1)|
    | 0  1  0  0  0  0 |  | f(n-3) |    |f(n-2)|
    | 0  0 c2 a2 b2  0 |* | g(n-1) | =  | g(n) |
    | 0  0  0  1  0  0 |  | g(n-2) |    |g(n-1)|
    | 0  0  0  0  1  0 |  | g(n-3) |    |g(n-2)|

input:
2
1 1 0
0 0 0
0 1 1
0 0 0
20000
10
1 2 3 4 5 6 7 8 9 10

1 1 1
1 1 1
2 2 2
2 2 2
20000
5
2 4 6 8 10

*/

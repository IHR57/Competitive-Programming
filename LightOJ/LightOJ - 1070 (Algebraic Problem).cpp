//Problem ID: LightOJ - 1070 (Algebraic Problem)
//Programmer: IQBAL HOSSAIN     Description: Matrix Expo
//Date: 03/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1070
#include <bits/stdc++.h>
#define MAX 5
using namespace std;

typedef unsigned long long ll;

struct Matrix{
    ll v[MAX][MAX];
    int row, col;
};

Matrix multiply(Matrix a, Matrix b)
{
    Matrix r;
    r.row = a.row, r.col = b.col;

    for(int i = 0; i < r.row; i++){
        for(int j = 0; j < r.col; j++){
            ll sum = 0;
            for(int k = 0; k < a.col; k++){
                sum = (sum + (a.v[i][k] * b.v[k][j]));
            }
            r.v[i][j] = sum;
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
    int test, caseno = 1;
    ll n, p, q;

    scanf("%d", &test);

    while(test--){
        scanf("%llu %llu %llu", &p, &q, &n);
        Matrix mat;
        memset(mat.v, 0, sizeof(mat));
        mat.row = 2, mat.col = 2;

        mat.v[0][0] = p, mat.v[0][1] = -q, mat.v[1][0] = 1;

        printf("Case %d: ", caseno++);

        if(n <= 2){
            if(n == 0)  printf("2\n");
            if(n == 1)  printf("%llu\n", p);
            if(n == 2)  printf("%llu\n", p * p - 2 * q);
        }
        else{
            mat = Power(mat, n - 2);
            Matrix temp;
            temp.row = 2, temp.col = 1;
            temp.v[0][0] = (p * p - 2 * q), temp.v[1][0] = p;
            mat = multiply(mat, temp);

            printf("%llu\n", mat.v[0][0]);
        }
    }

    return 0;
}

/*
    a^n + b^n = (a+b)*(a^(n-1) + b^(n-1)) - ab * (a^(n-2) + b^(n-2))
    so we can write,
    f(n) = p * f(n-1) - q * f(n-2);   where p = a + b, q = ab;

    | p  -q | |f(n-1)|   | f(n) |
    |       |*|      | = |      |
    | 1   0 | |f(n-2)|   |f(n-1)|
*/

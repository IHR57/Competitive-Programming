//Problem ID: LightOJ - 1142 (Summing up Powers II)
//Programmer: IQBAL HOSSAIN     Description: Matrix Exponenetiation
//Date: 03/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1142
#include <bits/stdc++.h>
#define MAX 35
#define MOD 10
using namespace std;

struct Matrix{
    int v[MAX][MAX];
};

Matrix I;       //identity matrix
int n;

Matrix multiply(Matrix a, Matrix b)
{
    Matrix r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int sum = 0;
            for(int k = 0; k < n; k++){
                sum = (sum + (a.v[i][k] * b.v[k][j]) % MOD) % MOD;
            }
            r.v[i][j] = sum % MOD;
        }
    }

    return r;
}

Matrix add(Matrix a, Matrix b)
{
    Matrix r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            r.v[i][j] = (a.v[i][j] + b.v[i][j] ) % MOD;
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

Matrix matExpo(Matrix mat, int p)
{
    if(p == 1)
        return mat;
    if(p % 2 != 0){
        return add(matExpo(mat, p - 1), Power(mat, p));
    }
    else{
        return multiply(matExpo(mat, p / 2), add(Power(mat, p / 2), I));
    }
}

int main()
{
    int test, caseno = 1, k;

    scanf("%d",  &test);

    while(test--){
        scanf("%d %d", &n, &k);
        Matrix mat;
        memset(I.v, 0, sizeof(I.v));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &mat.v[i][j]);
            }
            I.v[i][i] = 1;
        }

        mat = matExpo(mat, k);

        printf("Case %d:\n", caseno++);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d", mat.v[i][j] % MOD);
            }
            printf("\n");
        }
    }

    return 0;
}

/*
    if k is even, f(k) = f(k/2) + (A^3 + 1);
    if k i sodd,  f(k) = f(k-1) + A^k;
*/

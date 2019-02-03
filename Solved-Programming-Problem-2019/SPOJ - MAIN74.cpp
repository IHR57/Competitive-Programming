//Problem ID: SPOJ - MAIN74 (Euclids Algorithm Revisited)
//Programmer: IQBAL HOSSAIN     Description: Matrix Expo
//Date: 30/01/19
//Problem Link: https://www.spoj.com/problems/MAIN74/
#include <bits/stdc++.h>
#define MAX 10
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
            ll sum = 0;
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
    int test;
    ll n;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);
        Matrix mat;
        mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;
        mat.v[1][1] = 0;

        if(n == 0){
            printf("0\n");
        }
        else if(n == 1){
            printf("2\n");
        }
        else{
            mat = Power(mat, n + 1);
            ll result = (mat.v[0][0] * 1 + mat.v[0][1] * 1) % MOD;
            printf("%lld\n", result % MOD);
        }
    }

    return 0;
}

//Problem ID: SPOJ - RABBIT1 (Counting Rabbits)
//Programmer: IQBAL HOSSAIN     Description: Matrix Expo
//Date: 30/01/19
//Problem Link: https://www.spoj.com/problems/RABBIT1/
#include <bits/stdc++.h>
#define MAX 5
using namespace std;

typedef long long ll;

ll Mod;

struct Matrix
{
    ll v[MAX][MAX];
};

Matrix multiply(Matrix a, Matrix b)
{
    Matrix r;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            ll sum = 0;
            for(int k = 0; k < 2; k++){
                sum = (sum + (a.v[i][k] * b.v[k][j])) % Mod;
            }
            r.v[i][j] = sum % Mod;
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
    int test, n, m;
    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);
        Mod = (1LL<<(m));
        Matrix mat;

        memset(mat.v, 0, sizeof(mat.v));

        mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;
        mat.v[1][1] = 0;

        mat = Power(mat, n - 1);

        ll result = (mat.v[0][0] + mat.v[0][1] ) % Mod;

        printf("%lld\n", result);
    }

    return 0;
}

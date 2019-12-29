//Problem ID: LightOJ - 1096 (nth Term)
//Programmer: IQBAL HOSSAIN     Description: Matrix Expo
//Date: 02/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1096
#include <bits/stdc++.h>
#define MAX 5
#define MOD 10007
using namespace std;

struct Matrix{
    int v[MAX][MAX];
};

Matrix multiply(Matrix a, Matrix b)
{
    Matrix r;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int sum = 0;
            for(int k = 0; k < 4; k++){
                sum = (sum + (a.v[i][k] * b.v[k][j]) % MOD) % MOD;
            }
            r.v[i][j] = sum % MOD;
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
    int test, caseno = 1, n, a, b, c;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d %d", &n, &a, &b, &c);
        Matrix mat;

        memset(mat.v, 0, sizeof(mat.v));

        //given recurrence f(n) = a * f(n-1) + b * f(n-3) + c;
        mat.v[0][0] = a, mat.v[0][2] = b, mat.v[0][3] = 1;
        mat.v[1][0] = mat.v[2][1] = mat.v[3][3] = 1;

        printf("Case %d: ", caseno++);

        if(n <= 2){
            printf("0\n");
            continue;
        }
        mat = Power(mat, n - 2);
        int result = (c * mat.v[0][3]) % MOD;

        printf("%d\n", result);
    }

    return 0;
}

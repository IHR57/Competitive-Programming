//Problem ID: LightOJ - 1065 (Number Sequence)
//Programmer: IQBAL HOSSAIN     Description: Matrix Expo
//Date: 28/01/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1065
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int Mod;

struct matrix{
    int v[5][5];
    int row, col;
};

matrix multiply(matrix a, matrix b)
{
    matrix r;
    r.row = a.row, r.col = b.col;

    for(int i = 0; i < r.row; i++){
        for(int j = 0; j < r.col; j++){
            int sum = 0;
            for(int k = 0; k < a.col; k++){
                sum += (a.v[i][k] * b.v[k][j]) % Mod;
            }
            r.v[i][j] = sum % Mod;
        }
    }

    return r;
}

matrix Power(matrix mat, int p)
{
    if(p == 1)
        return mat;
    if(p % 2 == 1){
        return multiply(mat, Power(mat, p-1));
    }
    matrix ret = Power(mat, p / 2);
    ret = multiply(ret, ret);

    return ret;
}

int main()
{
    read; write;
    int a, b, n, m, test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d %d", &a, &b, &n, &m);

        Mod = 1;
        for(int i = 0; i < m; i++){
            Mod *= 10;
        }

        a %= Mod;
        b %= Mod;

        printf("Case %d: ", caseno++);
        if(n < 3){
            if(n == 0)  printf("%d\n", a);
            if(n == 1)  printf("%d\n", b);
            if(n == 2)  printf("%d\n", (a + b) % Mod);
        }
        else{
            matrix mat;
            mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;
            mat.v[1][1] = 0;

            mat.row = mat.col = 2;

            mat = Power(mat, n - 1);
            int result = (b * mat.v[0][0] + a * mat.v[0][1]) % Mod;

            printf("%d\n", result);
        }
    }

    return 0;
}

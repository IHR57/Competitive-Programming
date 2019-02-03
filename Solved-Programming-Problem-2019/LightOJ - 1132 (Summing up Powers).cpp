//Problem ID: LightOJ - 1132 (Summing up Powers)
//Programmer: IQBAL HOSSAIN     Description: Matrix Expo
//Date: 02/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1132
#include <bits/stdc++.h>
#define MAX 54
using namespace std;

typedef unsigned int ll;
int k;

struct Matrix{
    ll v[MAX][MAX];
};

Matrix multiply(Matrix a, Matrix b)
{
    Matrix r;
    for(int i = 0; i <= k + 1; i++){
        for(int j = 0; j <= k + 1; j++){
            ll sum = 0;
            for(int x = 0; x <= k + 1; x++){
                sum = (sum + (a.v[i][x] * b.v[x][j]));
            }
            r.v[i][j] = sum;
        }
    }

    return r;
}

Matrix Power(Matrix mat, long long p)
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
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
/*
    Recurrence: if n = 1, then f(1) = 1
    for n >= 2; f(x+1) = f(x) + (x+1)^k where (x + 1) = n
    we can compute (x+1)^k by pascal's triangle
    so, f(x+1) = f(x) + (kC0)x^k + (kC1)x^(k-1)+ ... + (kCk)x^0
*/

    ll pascal[MAX][MAX];
    pascal[0][0] = pascal[1][0] = pascal[1][1] = 1;

    for(int i = 2; i < MAX; i++){
        pascal[i][0] = pascal[i][i] = 1;
        for(int j = 1; j < i; j++){
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }

    long long n;
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %d", &n, &k);
        Matrix mat;
        memset(mat.v, 0, sizeof(mat.v));

        mat.v[0][0] = 1;
        int t = 0;
        for(int i = 1; i <= k + 1; i++){
            mat.v[0][i] = pascal[k][t++];
        }
        for(int i = 1; i <= k + 1; i++){
            t = 0;
            for(int j = i; j <= k + 1; j++){
                mat.v[i][j] = pascal[k-i+1][t++];
            }
        }

//        for(int i = 0; i <= k + 1; i++){
//            for(int j = 0; j <= k + 1; j++){
//                cout<<mat.v[i][j]<<" ";
//            }
//            cout<<endl;
//        }

        printf("Case %d: ", caseno++);
        if(n == 1){
            printf("1\n");
            continue;
        }
        mat = Power(mat, n - 1);

        ll result = 0;
        for(int i = 0; i <= k + 1; i++){
            result += (mat.v[0][i]);
        }

        printf("%u\n", result);
    }

    return 0;
}

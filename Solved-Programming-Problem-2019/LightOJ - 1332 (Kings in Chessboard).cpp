//Problem ID: LightOJ - 1332 (Kings in Chessboard)
//Programmer: IQBAL HOSSAIN     Description: Matrix Expo
//Date: 04/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1332
#include <bits/stdc++.h>
#define MAX 70
using namespace std;

int MP[MAX];

typedef unsigned int ll;
int idx;

struct Matrix
{
    ll v[MAX][MAX];
};

bool check(int a, int b)
{
    for(int i = 1; i <= (1<<9); i = i << 1){
        if(i & b){
            if((i & a))
                return false;
            if(i >= 2){
                if((i >> 1) & a)
                    return false;
            }
            if(i <= 256){
                if((i << 1) & a)
                    return false;
            }
        }
    }
    return true;
}

Matrix multiply(Matrix a, Matrix b)
{
    Matrix r;
    for(int i = 0; i < idx; i++){
        for(int j = 0; j < idx; j++){
            ll sum = 0;
            for(int k = 0; k < idx; k++){
                sum = (sum + (a.v[i][k] * b.v[k][j]));
            }
            r.v[i][j] = sum;
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
    int adj[] = {3, 6, 12, 24, 48, 96, 192, 384, 768};
    int arr[105];

    idx = 0;
    for(int i = 0; i < (1<<10); i++){
        if(__builtin_popcount(i) == 2){
            int flag = 0;
            //check two consecutive 1
            for(int j = 0; j < 9; j++){
                if(i == adj[j]){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                MP[i] = idx;
                arr[idx] = i;
                idx++;
            }
        }
    }

    Matrix mat;
    memset(mat.v, 0, sizeof(mat.v));

    for(int i = 0; i < idx; i++){
        for(int j = 0; j < idx; j++){
            if(check(arr[i], arr[j])){
                mat.v[MP[arr[i]]][MP[arr[j]]] = 1;
            }
        }
    }
    int test, n, caseno = 1;
    scanf("%d",  &test);

    while(test--){
        scanf("%d", &n);

        if(n == 1){
            printf("Case %d: 36\n", caseno++);
            continue;
        }
        Matrix ret = mat;
        ret = Power(ret, n - 1);

        ll result = 0;
        for(int i = 0; i < idx; i++){
            for(int j = 0; j < idx; j++){
                result += (ret.v[i][j]);
            }
        }

        printf("Case %d: %u\n", caseno++, result);
    }

    return 0;
}

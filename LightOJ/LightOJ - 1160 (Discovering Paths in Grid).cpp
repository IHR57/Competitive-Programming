//Problem ID: LightOJ - 1160 (Discovering Paths in Grid)
//Programmer: IQBAL HOSSAIN     Description: Matrix Expo
//Date: 03/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1160
#include <bits/stdc++.h>
#define MAX 40
#define MOD 1000000007
using namespace std;

typedef long long ll;

struct Matrix{
    ll v[MAX][MAX];
};
int idx;

bool check(int a, int b)
{
    int i = 0, j = 0;
    bool flag = true;

    while(i < 7 && j < 7){
        while(i < 7 && ((1<<i) & a) == 0)   i++;
        while(j < 7 && ((1<<j) & b) == 0)   j++;

        if(i >= 7 && j >= 7)    break;

        if(abs(i-j) == 1)   i++, j++;
        else if(i < 6 &&  j < 6 && i == j && ((1<<(i+1)) & a) && ((1<<(j+1)) & b))
            i += 2, j += 2;
        else{
            flag = false;
            break;
        }
    }

    return flag;
}

Matrix multiply(Matrix a, Matrix b)
{
    Matrix r;

    for(int i = 0; i < idx; i++){
        for(int j = 0; j < idx; j++){
            ll sum = 0;
            for(int k = 0; k < idx; k++){
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
    int test, caseno = 1, arr[150], temp, n;
    map<int, int> MP;

    idx = 0;
    for(int i = 1; i < (1<<7); i++){
        if(__builtin_popcount(i) == 4){
            if(MP.find(i) == MP.end()){
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
                mat.v[i][j] = 1;
            }
        }
    }

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int value = 0;
        for(int i = 0; i < 7; i++){
            scanf("%d", &temp);
            if(temp){
                value += (1 << (6-i));
            }
        }
        if(n == 1){
            printf("Case %d: 1\n", caseno++);
            continue;
        }
        Matrix ret = mat;
        ret = Power(ret, n - 1);
        value = MP[value];

        ll result = 0;
        for(int i = 0; i < idx; i++){
            result = (result + ret.v[i][value]) % MOD;
        }
        printf("Case %d: %lld\n", caseno++, result % MOD);
    }

    return 0;
}
/*
3
1
1 0 2 0 3 0 4
2
1 0 2 0 3 0 4
2
1 2 3 4 0 0 0
*/

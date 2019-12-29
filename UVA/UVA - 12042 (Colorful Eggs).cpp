//Problem ID: UVA - 12042 (Colorful Eggs)
//Programmer: IQBAL HOSSAIN     Description: Matrix Expo
//Date: 30/01/19
//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3193
#include <bits/stdc++.h>
#define MAX 62
#define MOD 1000000007
using namespace std;

typedef long long ll;

int n;
struct Matrix{
    ll v[MAX][MAX];
};

Matrix I;           //identity Matrix

Matrix multiply(Matrix a, Matrix b)
{
    Matrix r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ll sum = 0;
            for(int k = 0; k < n; k++){
                sum = (sum + (a.v[i][k] * b.v[k][j]) % MOD) % MOD;
            }
            r.v[i][j] = sum % MOD;
        }
    }

    return r;
}

Matrix Power(Matrix mat, int p)
{
    if(p == 0)
        return I;
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
    int test, d;
    vector<ll> arr;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &d);

        arr.clear();
        ll value;
        for(int i = 0; i < n; i++){
            scanf("%lld", &value);
            arr.push_back(value);
        }

        reverse(arr.begin(), arr.end());

        Matrix mat;
        memset(mat.v, 0, sizeof(mat.v));
        memset(I.v, 0, sizeof(I.v));

        //Preparing the matrix
        for(int i = 0; i < n; i++)
            mat.v[i][0] = 1;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                mat.v[i][j] = 1;
            }
            I.v[i][i] = 1;
        }

        mat = Power(mat, d - 1);

        vector<ll> ans;
        for(int i = 0; i < n; i++){
            ll sum = 0;
            for(int j = 0; j < 1; j++){
                for(int k = 0; k < n; k++){
                    sum = (sum + (mat.v[i][k] * arr[k]) % MOD) % MOD;
                }
            }
            ans.push_back(sum % MOD);
        }
        reverse(ans.begin(), ans.end());

        for(int i = 0; i < ans.size() - 1; i++){
            printf("%lld ", ans[i]);
        }
        printf("%lld\n", ans[ans.size() - 1]);
        ans.clear();
    }

    return 0;
}

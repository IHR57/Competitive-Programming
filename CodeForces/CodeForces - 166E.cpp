#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000007
using namespace std;

typedef long long ll;

struct Matrix
{
    ll v[5][5];
};

Matrix multiply(Matrix a, Matrix b)
{
    Matrix r;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            ll sum = 0;
            for(int k = 0; k < 4; k++){
                sum = (sum + (a.v[i][k] * b.v[k][j]) % MOD) % MOD;
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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    Matrix mat;
    memset(mat.v, 0, sizeof(mat.v));
    mat.v[0][1] = mat.v[0][2] = mat.v[0][3] = 1;
    mat.v[1][0] = mat.v[1][2] = mat.v[1][3] = 1;
    mat.v[2][0] = mat.v[2][1] = mat.v[2][3] = 1;
    mat.v[3][0] = mat.v[3][1] = mat.v[3][2] = 1;

    cin>>n;

    if(n == 1){
        cout<<0<<endl;
        return 0;
    }

    mat = Power(mat, n);

    cout<<mat.v[0][0]<<endl;

    return 0;

}

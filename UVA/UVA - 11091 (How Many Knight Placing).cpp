//Problem ID: UVA - 11091 (How Many Knight Placing?)
//Programmer: IQBAL HOSSAIN     Description: Matrix Exponentiation
//Date: 04/02/19
//Solution Idea: http://www.progkriya.org/gyan/matrix-expo.html#
#include <bits/stdc++.h>
#define MAX 75
#define MOD 10007
using namespace std;

typedef long long ll;

struct Matrix{
    int v[MAX][MAX];
};

struct PP{
    int fst, snd;
};

PP pos[MAX];
int MP[MAX][MAX];

bool check(int a, int b)        //checking validity for two columns
{
    for(int i = 1; i <= (1<<5); i = i << 1){
        if(i & b){
            if(i >= 4){
                if((i >> 2) & a)    return false;
            }
            if(i < 16){
                if((i << 2) & a)    return false;
            }
        }
    }
    return true;
}

bool checkThree(int a, int c, int b)
{
    for(int i = 1; i <= (1<<5); i = i << 1){
        if(i & b){
            if(i >= 4){
                if((i >> 2) & a)    return false;
            }
            if(i < 16){
                if((i << 2) & a)    return false;
            }
            if(i >= 2){
                if((i >> 1) & c)    return false;
            }
            if(i < 32){
                if((i << 1) & c)    return false;
            }
        }
    }
    return true;
}

Matrix multiply(Matrix a, Matrix b)
{
    Matrix r;
    for(int i = 0; i < 69; i++){
        for(int j = 0; j < 69; j++){
            int sum = 0;
            for(int k = 0; k < 69; k++){
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
    int arr[MAX], idx = 0, k = 0;
    for(int i = 1; i < (1<<6); i++){
        if(__builtin_popcount(i) == 2){
            arr[idx++] = i;
        }
    }

    for(int i = 0; i < idx; i++){
        for(int j = 0 ; j < idx; j++){
            if(check(arr[i], arr[j])){
                MP[arr[i]][arr[j]] = k;
                pos[k].fst = arr[i];
                pos[k].snd = arr[j];
                k++;
            }
        }
    }
//    cout<<k<<endl;

    Matrix mat;
    memset(mat.v, 0, sizeof(mat.v));

    for(int i =  0; i < 69; i++){
        for(int j = 0; j < idx; j++){
            if(checkThree(pos[i].snd, pos[i].fst, arr[j])){
                mat.v[MP[pos[i].snd][arr[j]]][MP[pos[i].fst][pos[i].snd]] = 1;
            }
        }
    }

    int test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        Matrix ret = mat;
        if(n <= 2){
            if(n == 1)  printf("%d\n", 15);
            if(n == 2)  printf("%d\n", 69);
        }
        else{
            ret = Power(ret, n - 2);
            int result = 0;
            for(int i = 0; i < 69; i++){
                for(int j = 0; j < 69; j++){
                    result = (result + ret.v[i][j]) % MOD;
                }
            }

            printf("%d\n", result);
        }
    }

    return 0;
}

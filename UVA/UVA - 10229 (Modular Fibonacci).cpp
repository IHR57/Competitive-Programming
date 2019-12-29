//BISMILLAHIR RAHMANIR RAHIM
//Problem ID: UVA 10229 (Modular Fibonacci)
//Programmer: IQBAL HOSSAIN     Description: Matrix Expo
//Date: 28/01/19
//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1170
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <list>
#define cos(a) cos(a*pi/180)
#define sin(a) sin(a*pi/180)
#define tan(a) tan(a*pi/180)
#define cosi(a) acos(a)/(pi/180)
#define sini(a) asin(a)/(pi/180)
#define tani(a) atan(a)/(pi/180)
#define read (freopen("input.txt", "r", stdin))
#define write (freopen("output.txt", "w", stdout))
#define fastIO (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef priority_queue<int,vector<int>,greater<int> > pq;

const int inf = 1<<28;
int dirx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int diry[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dx[]= { -1, 1, 0, 0 };
int dy[]= { 0, 0, -1, 1 };

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}
ll Mod;

struct matrix{
    ll v[5][5];
    int row, col;
};

matrix multiply(matrix a, matrix b)
{
    matrix r;
    r.row = a.row;
    r.col = b.col;

    for(int i = 0; i < r.row; i++){
        for(int j = 0; j < r.col; j++){
            ll sum = 0;
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
//    if(p == 0){
//        mat.v[0][0] = 1, mat.v[1][1] = 1;
//        mat.v[0][1] = mat.v[1][0] = 0;
//        return mat;
//    }
    if(p == 1)
        return mat;
    if(p % 2 == 1){
        return multiply(mat, Power(mat, p - 1));
    }
    matrix ret = Power(mat, p / 2);
    ret = multiply(ret, ret);

    return ret;
}

int main()
{
    read; write;
    int n, m;

    while(scanf("%d %d", &n, &m) == 2){
        matrix mat;
        mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;
        mat.v[1][1] = 0;

        Mod = (1LL << m);

        if(n <= 2){
            if(n == 0)  printf("%d\n", 0);
            else        printf("%d\n", 1 % Mod);
        }
        else{
            mat.row = mat.col = 2;
            mat = Power(mat, n - 1);

            ll result = (mat.v[0][0]) % Mod;

            printf("%d\n", result);
        }
    }

    return 0;
}

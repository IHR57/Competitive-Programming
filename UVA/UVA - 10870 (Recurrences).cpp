//Problem ID: UVA - 10870 (Recurrences)
//Programmer: IQBAL HOSSAIN     Description: Matrix Expo
//Date: 28/01/19
//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1811
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
#define MAX 16
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
int Mod;

struct matrix{
    ll v[MAX][MAX];
    int row, col;
};

matrix multiply(matrix a, matrix b)
{
    matrix r;
    r.row = a.row, r.col = b.col;

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
    int d, n, m, a[MAX], f[MAX];

    while(scanf("%d %d %d", &d, &n, &m) == 3){
        if(!d && !n && !m)
            break;
        for(int i = 0; i < d; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < d; i++){
            scanf("%d", &f[i]);
        }

        Mod = m;
        matrix mat;
        mat.row = mat.col = d;

        memset(mat.v, 0, sizeof(mat.v));

        for(int i = 0; i < d; i++)
            mat.v[0][i] = a[i] % Mod;
        int k = 0;
        for(int i = 1; i < d; i++){
            mat.v[i][k] = 1 % Mod;
            k++;
        }
//        for(int i = 0; i < d; i++){
//            for(int j = 0; j < d; j++){
//                cout<<mat.v[i][j]<<" ";
//            }
//            cout<<endl;
//        }

        if(n <= d){
            printf("%d\n", f[d-1]);
            continue;
        }
        mat = Power(mat, n - d);

        ll result = 0;
        k = 0;
        for(int i = d - 1; i >= 0; i--){
            result += (f[i] * mat.v[0][k]) % Mod;
            k++;
        }

        printf("%lld\n", result % Mod);
    }

    return 0;
}

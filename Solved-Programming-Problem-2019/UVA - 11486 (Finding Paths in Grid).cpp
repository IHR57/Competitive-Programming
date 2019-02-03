//BISMILLAHIR RAHMANIR RAHIM
//Problem ID: UVA - 11486 (Finding Paths in grid)
//Programmer: IQBAL HOSSAIN     Description: Matrix Expo
//Date: 29/01/19
//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2481
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
#define MAX 40
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

struct Matrix{
    ll v[MAX][MAX];
    int row, col;
};

Matrix multiply(Matrix a, Matrix b)
{
    Matrix r;
    r.row = a.row, r.col = b.col;
    for(int i = 0; i < r.row; i++){
        for(int j = 0; j < r.col; j++){
            ll sum = 0;
            for(int k = 0; k < a.col; k++){
                sum += (a.v[i][k] * b.v[k][j]) % MOD;
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

bool check(int a, int b)
{
    int i = 0, j = 0;
    bool flag = true;
    while(i < 7 && j < 7){
        while(i < 7 && (((1 << i) & a) == 0))
            i++;
        while(j < 7 && (((1 << j) & b) == 0))
            j++;
        if(i >= 7 && j >= 7)
            break;
        if(abs(i - j) == 1)
            i++, j++;
        else if(i < 6 && j < 6 && i == j && ((1 << ( i + 1)) & a) && ((1 << (j + 1)) & b)){
            i += 2, j += 2;
        }
        else{
            flag = false;
            break;
        }
    }

    return flag;
}

int main()
{
    //read; write;
    int arr[105], idx = 0;

    map<int, int> myMap;

    Matrix mat;
    memset(mat.v, 0, sizeof(mat.v));

    for(int i = 1; i < (1<<7); i++){
        if(__builtin_popcount(i) == 4){
            if(myMap.find(i) == myMap.end()){
                myMap[i] = idx;
                arr[idx] = i;
                idx++;
            }
        }
    }
    for(int i = 0; i < idx; i++){
        for(int j = 0; j < idx; j++){
            if(check(arr[i], arr[j])){
                mat.v[i][j] = 1;
            }
        }
    }

    mat.row = mat.col = idx;
    int test, n, value;

    cin>>test;

    while(test--){
        cin>>n;
        int k = 6, val = 0;
        for(int i = 0; i < 7; i++){
            cin>>value;
            if(value > 0){
                val += (1 << (k - i));
            }
        }
        Matrix temp = mat;
        if(n == 1){
            cout<<1<<endl;
            continue;
        }

        temp = Power(temp, n - 1);
        //cout<<"NO PROB :)"<<endl;
        int t = myMap[val];

        ll result = 0;
        for(int i = 0; i < idx; i++){
            result = (result + temp.v[i][t]) % MOD;
        }

        cout<<result<<endl;
    }

    return 0;
}

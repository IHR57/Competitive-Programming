#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <iomanip>
#include <stack>
#define MAX 100005
#define pb push_back
#define all(c) (c.begin(), c.end())
#define mem(a, b) memset(a, b, sizeof(a))
#define EPS 1e-10
#define PI 3.14159265358979323846
#define MOD 1000000007
#define mp make_pair
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector< vector<int> >vii;
typedef vector<double> vd;
typedef vector<string> vs;
typedef long long ll;
typedef unsigned long long ull;

const int inf = 1<<29;
ll fact[2*MAX];
int bit[2*MAX];

void update(int idx, int n, int value)
{
    while(idx <= n){
        bit[idx] += value;
        idx += (idx & -idx);
    }
}

int query(int idx, int n)
{
    int sum = 0;
    while(idx > 0){
        sum += bit[idx];
        idx -= (idx & -idx);
    }

    return sum;
}
int main()
{
    //read; write;
    int test, n, a[2*MAX];

    fact[0] = 1;
    for(int i = 1; i < 2*MAX; i++){
        fact[i] = (i * fact[i-1]) % MOD;
    }

    //cout<<fact[20]<<" "<<fact[30]<<endl;
    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }

        mem(bit, 0);

        ll result = 0;
        for(int i = n - 1; i >= 0; i--){
            int lesser = query(a[i]-1, n);
            result += (lesser * fact[n-i-1]) % MOD;
            update(a[i], n, 1);
        }

        printf("%lld\n", (result+1) % MOD);
    }

    return 0;
}

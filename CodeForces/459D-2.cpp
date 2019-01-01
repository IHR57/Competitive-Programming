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
#define MAX 1000005
#define pb push_back
#define all(c) (c.begin(), c.end())
#define mem(a, b) memset(a, b, sizeof(a))
#define EPS 1e-10
#define PI 3.14159265358979323846
#define MOD 10000000007
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

int n, sf[MAX], pf[MAX], a[MAX];
ll tree[MAX];
map<int, int> m1, m2;

void update(int idx, ll value)
{
    while(idx <= n){
        tree[idx] += value;
        idx += (idx & -idx);
    }
}

ll getSum(int idx)
{
    ll sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }

    return sum;
}

int main()
{
    fastIO;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>a[i];
        m1[a[i]]++;
        pf[i] = m1[a[i]];
    }

    ll sum = 0;

    for(int i = n - 1; i >= 0; i--){
        m2[a[i]]++;
        sf[i] = m2[a[i]];
    }

    for(int i = n-1; i >= 0; i--){
        sum += getSum(pf[i]);
        update(sf[i]+1, 1);
    }

    cout<<sum<<endl;

	return 0;
}

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
#include <stack>
#define MAX 30005
#define pb push_back
#define all(c) (c.begin(), c.end())
#define mem(a, b) memset(a, b, sizeof(a))
#define EPS 1e-10
#define PI 3.14159265358979323846
#define mp make_pair
#define fin freopen("input.txt", "r", stdin);
#define fout freopen("output.txt", "w", stdout);
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

int tree[MAX];

void update(int idx, int n, int x)
{
    while(idx <= n){
        tree[idx] += x;
        idx += (idx & -idx);
    }
}

int query(int idx)
{
    int sum = 0;

    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }

    return sum;
}

int main()
{
	//fin; fout;
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test, n;
    char str[100];

    cin>>test;

    while(test--){
        cin>>n;
        mem(tree, 0);
        map<string, int> myMap;
        for(int i = 1; i <= n; i++){
            cin>>str;
            myMap[str] = i;
        }
        int sum = 0, idx[n+10];

        for(int i = 1; i <= n; i++){
            cin>>str;
            idx[i] = myMap[str];
        }

        for(int i = n; i >= 1; i--){
            sum += query(idx[i]);
            update(idx[i], n, 1);
        }

        cout<<sum<<endl;
    }

	return 0;
}

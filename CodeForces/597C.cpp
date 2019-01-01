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
#define MAX 100005
#define pb push_back
#define all(c) (c.begin(), c.end())
#define mem(a, b) memset(a, b, sizeof(a))
#define EPS 1e-10
#define PI 3.14159265358979323846
#define mp make_pair
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

ll tree[11][MAX], arr[MAX];

void update(int k, int idx, ll value)
{
    while(idx < MAX){
        tree[k][idx] += value;
        idx += (idx & -idx);
    }
}

ll query(int k, int idx)
{
    ll sum = 0;
    while(idx > 0){
        sum += tree[k][idx];
        idx -= (idx & -idx);
    }

    return sum;
}

int main()
{
	//read; write;
    int n, k;

    cin>>n>>k;     //length and subsequence length

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        update(0, arr[i], 1);       //1 length subsequence
        for(int j = k; j > 0; j--){
            ll val = query(j-1, arr[i] - 1);        //count number of element in the array are less than in given number
            //cout<<val<<endl;
            update(j, arr[i], val);     //update
        }
    }

    cout<<query(k, n)<<endl;

	return 0;
}

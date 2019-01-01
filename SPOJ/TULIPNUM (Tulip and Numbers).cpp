#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <list>
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
#define MOD 10000000007
#define INF 2147483647
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


int main()
{
	//read; write;
	int test, caseNo = 1, a[MAX], counter[MAX];
	int n, q;

	scanf("%d", &test);

	while(test--){
        scanf("%d %d", &n, &q);
        a[0] = -1;
        mem(counter, 0);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);         //numbers are sorted in increasing order
            if(a[i] != a[i-1]){
                counter[i] = counter[i-1] + 1;
            }
            else{
                counter[i] = counter[i-1];
            }
        }

        int x, y;

        printf("Case %d:\n", caseNo++);

        for(int i = 0; i < q; i++){
            scanf("%d %d", &x, &y);
            printf("%d\n", counter[y] - counter[x] + 1);
        }
	}

	return 0;
}

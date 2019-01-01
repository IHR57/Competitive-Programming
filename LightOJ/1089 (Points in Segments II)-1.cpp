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
#define MAX 50005
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

int main()
{
    //read; write;
    int test, started[MAX], ended[MAX], q, n, value, caseNo = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++){
            scanf("%d %d", &started[i], &ended[i]);     //starting and ending point of a segment
        }

        sort(started, started+n);
        sort(ended, ended+n);

        printf("Case %d:\n", caseNo++);

        for(int i = 0; i < q; i++){
            scanf("%d", &value);
            int a = upper_bound(started, started+n, value) - started;
            int b = lower_bound(ended, ended+n, value) - ended;

            printf("%d\n", a - b);
        }
    }

    return 0;
}

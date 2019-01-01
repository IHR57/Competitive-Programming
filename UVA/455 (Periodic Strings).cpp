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
#define pb push_back
#define all(v) (v.begin(), v.end())
#define mem(a, b) memset(a, b, sizeof(a))
#define EPS 1e-10
#define PI acos(-1)
#define MOD 1000000007
#define INF 2147483647
#define mp make_pair
#define sin(a) sin(a*pi/180)
#define cos(a) cos(a*pi/180)
#define tan(a) tan(a*pi/180)
#define sini(a) asin(a) / (pi/180)
#define cosi(a) acos(a) / (pi/180)
#define tani(a) atan(a) / (pi/180)
#define dis(x1, y1, x2, y2) ((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2))
#define debug (printf("I AM HERE:)\n"))
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 105
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;

int pi[MAX];

void prefixFunction(char str[])
{
    memset(pi, 0, sizeof(pi));
    int len = strlen(str);

    for(int i = 1; i < len; i++){
        int j = pi[i-1];
        while(j > 0 && str[i] != str[j])
            j = pi[j-1];
        if(str[i] == str[j])
            j++;
        pi[i] = j;

    }
}

int main()
{
    //read; write;
    int test, line = 0;
    char str[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%s", str);
        prefixFunction(str);
        int len = strlen(str);
        int k = len - pi[len-1];
        if(line)                //blank line between two consecutive cases
            printf("\n");
        line = 1;

        if(len % k == 0){
            printf("%d\n", k);              //found period, smaller than n
        }
        else{
            printf("%d\n", len);
        }
    }

    return 0;
}

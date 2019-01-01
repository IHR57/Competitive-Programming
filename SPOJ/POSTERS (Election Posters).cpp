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
#define MAX 10000005
#define pb push_back
#define all(c) (c.begin(), c.end())
#define memo(a, b) memset(a, b, sizeof(a))
#define EPS 1e-8
#define PI 3.14159265358979323846
#define mp make_pair
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;

int lazy[4*MAX];
set<int> s;

void shift(int id, int low, int high, int value)
{
    lazy[2*id] = lazy[2*id+1] = value;
    lazy[id] = 0;
}

void update(int id, int low, int high, int i, int j, int value)
{
    if(lazy[id]){
        if(low != high)
            shift(id, low, high, lazy[id]);
    }
    if(low > high || i > high || j < low)
        return;
    if(low >= i && high <= j){
        if(low != high)
            shift(id, low, high, value);
        else
            lazy[id] = value;
        return;
    }

    int mid = (low + high) >> 1;
    update(id*2, low, mid, i, j, value);
    update(id*2+1, mid + 1, high, i, j, value);
}

void Count(int id, int low, int high)       //return number of diffrent poster
{
    if(lazy[id]){
        //cout<<lazy[id]<<endl;
        s.insert(lazy[id]);
        return;
    }
    if(low == high){
        return;
    }

    int mid = (low + high) >> 1;
    Count(id*2, low, mid);
    Count(id*2+1, mid + 1, high);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int test, caseNo = 1, x, y, q, Max;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &q);
        memo(lazy, 0);      //initialize lazy by 0
        pii coord[50000];
        Max = -1;

        for(int i = 1; i <= q; i++){
            scanf("%d %d", &x, &y);
            if(y > Max)     Max = y;
            x--, y--;
            coord[i] = mp(x, y);
        }

        for(int i = 1; i <= q; i++){
            update(1, 0, 2*Max-1, coord[i].first, coord[i].second, i);
        }

        Count(1, 0, 2*Max-1);

        printf("%d\n", s.size());
        s.clear();
    }

    return 0;
}

//Problem ID: LightOJ - 1016 (Brush II)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 12/01/19
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
#define MOD 1000000007
#define MAX 50005
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

int coordY[MAX];

struct point{
    int x, y;
};
bool compare(point A, point B)
{
    return A.y < B.y;
}

point coord[MAX];

int main()
{
    int test,  caseNo = 1, p, w;

    scanf("%d",  &test);

    while(test--){
        scanf("%d %d", &p, &w);

        for(int i = 0; i < p; i++){
            scanf("%d %d", &coord[i].x, &coord[i].y);
        }

        sort(coord, coord + p, compare);

        for(int i = 0; i < p; i++){
            coordY[i] = coord[i].y;
        }

        int numberofMove = 0;
        for(int i = 0; i < p; ){
            int idx = upper_bound(coordY, coordY + p, coordY[i] + w) - coordY;
            numberofMove++;
            i = idx;
        }

        printf("Case %d: %d\n", caseNo++, numberofMove);
    }

    return 0;
}

/**
1
8 2
5 -3
2 -1
-3 -1
5 0
7 2
9 2
-8 4
-9 7
**/

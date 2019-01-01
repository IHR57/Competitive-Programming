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
#define MAX 710
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

int arr[MAX*MAX];

struct node
{
    int val, idx;

}block[MAX][MAX];

bool cmp(node a, node b)
{
    return a.val < b.val;
}

int query(int low, int high, int value)
{
    int cl = low / MAX, cr = high / MAX;
    int cnt = 0;

    if(cl == cr){
        for(int i = low; i <= high; i++){
            if(arr[i] > value)
                cnt++;
        }
    }
    else{
        int End = (cl + 1) * MAX - 1;
        for(int i = low; i <= End; i++){
            if(arr[i] > value)
                cnt++;
        }
        for(int i = cl + 1; i <= cr - 1; i++){
            int l = 0, r = MAX - 1;
            while(l < r){       //binary Search
                int mid = (l + r + 1) >> 1;
                if(block[i][mid].val <= value)
                    l = mid;
                else
                    r = mid - 1;
            }
            if(block[i][l].val > value) l--;
            cnt += (MAX - l -1);
        }
        for(int i = cr * MAX; i <= high; i++){
            if(arr[i] > value)
                cnt++;
        }
    }

    return cnt;
}

int main()
{
	//read; write;
    int n, cmd, l, r, value, q;

    scanf("%d", &n);

    for(int i = 0, j = (n - 1) / MAX; i < MAX; i++){        //initialize last block
        block[j][i].val = INF, block[j][i].idx = -1;
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        block[i/MAX][i%MAX].val = arr[i];
        block[i/MAX][i%MAX].idx = i;
    }

    for(int i = (n - 1) / MAX; i >= 0; i--){
        sort(block[i], block[i]+MAX, cmp);
    }

    scanf("%d", &q);

    while(q--){
        scanf("%d", &cmd);
        if(cmd == 0){
            scanf("%d %d %d", &l, &r, &value);
            l--, r--;
            int result = query(l, r, value);
            printf("%d\n", result);
        }
        else{
            int x, p;
            scanf("%d %d", &l, &r);
            l--, r;
            x = l / MAX;        //block it belongs to

            int k;
            for(k = 0; block[x][k].idx != l; k++);

            for(; k < MAX; k++){
                block[x][k].val = block[x][k+1].val;
                block[x][k].idx = block[x][k+1].idx;
            }
            for(k = MAX - 2; k >= 0 && block[x][k].val > r; k--){
                block[x][k+1].val = block[x][k].val;
                block[x][k+1].idx = block[x][k].idx;
            }
            block[x][k+1].val = r;
            block[x][k+1].idx = l;
            arr[l] = r;
        }
    }

	return 0;
}

/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: Psychedelic
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int ans = INF, v;

void check(vector<int>& st, int type, int x1, int y1, int x2, int y2)
{
    if(!st.empty()){
        int tx = lower_bound(st.begin(), st.end(), y1) - st.begin();
        if(tx >= st.size()){
            tx--;
        }
        int temp = abs(y1 - st[tx]);
        int t = abs(x2 - x1);
        if(type)
            temp += t / v + ((t % v) != 0);
        else
            temp += t;

        temp += abs(y2 - st[tx]);
        ans = min(ans, temp);

        tx --;
        if(tx < 0)
            return;

        temp = abs(y1 - st[tx]);
        t = abs(x2 - x1);
        if(type)
            temp += t / v + ((t % v) != 0);
        else
            temp += t;

        temp += abs(y2 - st[tx]);
        ans = min(ans, temp);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, m, cl, ce, q, x1,  y1, x2, y2, val;

    scanf("%d %d %d %d %d", &n, &m, &cl, &ce, &v);
    vector<int> stairs, elevators;

    for(int i = 0; i < cl; i++){
        scanf("%d", &val);
        stairs.pb(val);
    }

    for(int i = 0; i < ce; i++){
        scanf("%d", &val);
        elevators.pb(val);
    }

    scanf("%d", &q);

    for(int i = 0; i < q; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        ans = INF;
        if(x1 == x2){
            printf("%d\n", abs(y1 - y2));
            continue;
        }
        check(stairs, 0, x1, y1, x2, y2);
        check(elevators, 1, x1, y1, x2, y2);

        printf("%d\n", ans);
    }



    return 0;
}

/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int n, q, arr[MAX], idx[MAX];
int tree[4*MAX];

void build(int v, int tl, int tr)
{
    if(tl == tr){
        tree[v] = -1;
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    tree[v] = max(tree[v*2], tree[v*2+1]);
}

void update(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr){
        tree[v] = val;
    }
    else{
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            update(v * 2, tl, tm, pos, val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, val);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return -1;
    if(l == tl && r == tr)
        return tree[v];
    int tm = (tl + tr) >> 1;
    return max(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int cmd, p, x;
    cin>>n;
    memset(idx, -1, sizeof(idx));
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cin>>q;

    build(1, 0, q - 1);

    for(int i = 0; i < q; i++){
        cin>>cmd;
        if(cmd == 1){
            cin>>p>>x;
            p--;
            idx[p] = i;
            arr[p] = x;
        }
        else{
            cin>>x;
            update(1, 0, q - 1, i, x);
        }
    }

    int temp;
    for(int i = 0; i < n; i++){
        x = idx[i];
        if(x == -1){
            temp = query(1, 0, q - 1, 0, q - 1);
            (temp > arr[i]) ? cout<<temp<<" " : cout<<arr[i]<<" ";
        }
        else{
            temp = query(1, 0, q - 1, x, q - 1);
            (temp > arr[i]) ? cout<<temp<<" " : cout<<arr[i]<<" ";
        }
    }

    return 0;
}

/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
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
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<pair<ii, int> >v;
ll cs[4*MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, m, k, x, y;
    cin>>n>>m>>k;
    map<ii, int> mp;

    v.pb(mk(mk(0, 0), 0));
    mp[mk(0, 0)] = 1;

    int j = 1, idx = 2;
    cs[1] = 0;
    while(true){
        int tx, ty, dist;
        if(v[j-1].ff.ff == 0){
            int x = min((m - v[j-1].ff.ss), (n - v[j-1].ff.ff));
            tx = v[j-1].ff.ff + x, ty = v[j-1].ff.ss + x;
            if(mp[mk(tx, ty)] != 0){
                x = min((v[j-1].ff.ss), (n - v[j-1].ff.ff));
                tx = v[j-1].ff.ff + x, ty = v[j-1].ff.ss - x;
            }
        }
        else if(v[j-1].ff.ff == n){
            //cout<<"HERE"<<endl;
            int x = min((m - v[j-1].ff.ss), n);
            tx = v[j-1].ff.ff - x, ty = v[j-1].ff.ss + x;
            if(mp[mk(tx, ty)] != 0){
                x = min(v[j-1].ff.ss, n);
                tx = v[j-1].ff.ff - x, ty = v[j-1].ff.ss - x;
            }
        }
        else if(v[j-1].ff.ss == 0){
            int x = min(m, n - v[j-1].ff.ff);
            tx = v[j-1].ff.ff + x, ty = v[j-1].ff.ss + x;
            if(mp[mk(tx, ty)] != 0){
                x = min(m, v[j-1].ff.ff);
                tx = v[j-1].ff.ff - x, ty = v[j-1].ff.ss + x;
            }
        }
        else if(v[j-1].ff.ss == m){
            int x = min(m, v[j-1].ff.ff);
            tx = v[j-1].ff.ff - x, ty = v[j-1].ff.ss - x;
            if(mp[mk(tx, ty)] != 0){
                x = min(n - v[j-1].ff.ff, m);
                tx = v[j-1].ff.ff + x, ty = v[j-1].ff.ss - x;
            }
        }
        //cout<<tx<<" "<<ty<<endl;
        if((tx == 0 && ty == 0) || (tx == n && ty == m) || (tx == 0 && ty == m) || (tx == n && ty == 0))
            break;
        if(mp[mk(tx, ty)] != 0)
                break;
        dist = abs(tx - v[j-1].ff.ff);
        cs[idx] = cs[idx-1] + dist;
        //cout<<cs[idx]<<endl;
        mp[mk(tx, ty)] = idx++;
        v.pb(mk(mk(tx, ty), dist));
        j++;
    }   

    for(int i = 0; i < k; i++){
        cin>>x>>y;
        int Idx = 1e8;
        int t = min(abs(n - x), abs(m - y));
        int tx = x + t, ty = y + t;
        int ansx, ansy;
        //cout<<tx<<" "<<ty<<endl;
        if(mp[mk(tx, ty)] != 0){
            if(mp[mk(tx, ty)] < Idx){
                Idx = mp[mk(tx, ty)];
                ansx = tx, ansy = ty;
            }
        }
        t = min(abs(0 - x), abs(m - y));
        tx = x - t, ty = y + t;
        //cout<<tx<<" "<<ty<<endl;
        if(mp[mk(tx, ty)] != 0)
            if(mp[mk(tx, ty)] < Idx){
                Idx = mp[mk(tx, ty)];
                ansx = tx, ansy = ty;
            }

        t = min(x, y);
        tx = x - t, ty = y - t;
        //cout<<tx<<" "<<ty<<endl;
        if(mp[mk(tx, ty)] != 0)
            if(mp[mk(tx, ty)] < Idx){
                Idx = mp[mk(tx, ty)];
                ansx = tx, ansy = ty;
            }

        t = min(abs(n - x), y);
        tx = x + t, ty = y - t;
        //cout<<tx<<" "<<ty<<endl;
        if(mp[mk(tx, ty)] != 0)
            if(mp[mk(tx, ty)] < Idx){
                Idx = mp[mk(tx, ty)];
                ansx = tx, ansy = ty;
            }

        if(Idx == 1e8){
            cout<<-1<<endl;
            continue;
        }
        //cout<<ansx<<" "<<ansy<<endl;
        cout<<cs[Idx] + abs(ansx - x)<<endl;
    }

    return 0;
}

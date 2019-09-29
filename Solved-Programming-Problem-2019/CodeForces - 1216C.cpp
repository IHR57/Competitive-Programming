//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

struct rect
{
    int x1, y1, x2, y2;
};

rect interRect(rect p, rect q)
{
    rect res;
    res.x1 = max(p.x1, q.x1);
    res.y1 = max(p.y1, q.y1);
    res.x2 = min(p.x2, q.x2);
    res.y2 = min(p.y2, q.y2);
    if(res.x1 > res.x2 || res.y1 > res.y2){
        res.x1 = res.x2 = res.y1 = res.y2 = 0;
    }
    return res;
}

ll area(rect p)
{
    if(p.x1 > p.x2 || p.y1 > p.y2)
        return 0;
    return 1LL * (p.x2 - p.x1) * (p.y2 - p.y1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    rect p, q, r;
    cin>>p.x1>>p.y1>>p.x2>>p.y2;
    cin>>q.x1>>q.y1>>q.x2>>q.y2;
    cin>>r.x1>>r.y1>>r.x2>>r.y2;

    rect pq = interRect(p, q);  //intersecting rectangle of p and q
    rect pr = interRect(p, r);
    rect pqr = interRect(pq, pr);      //intersecting rectangle of p, q and r

    ll temp = area(pq) + area(pr) - area(pqr);
    if(area(p) == temp){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;

    return 0;
}

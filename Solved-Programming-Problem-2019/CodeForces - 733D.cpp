#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 1e17
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

map<ii, ii> mp;
int fstIdx, sndIdx, Max = 0;

void check(int a, int b, int c, int idx)
{
    if(mp.count(mk(a, b)) == 0)
        return;
    ii temp = mp[mk(a, b)];
    int x = min(min(a, b), temp.ff + c);
    if(x > Max){
        Max = x;
        fstIdx = idx, sndIdx = temp.ss;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int a, b, c, n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>a>>b>>c;
        if(a > b)   swap(a, b);
        if(a > c)   swap(a, c);
        if(b > c)   swap(b, c);
        if(a > Max){
            Max = a;
            fstIdx = i, sndIdx = -1;
        }
        check(a, b, c, i);
        check(a, c, b, i);
        check(b, c, a, i);

        mp[mk(a, b)] = max(mp[mk(a, b)], mk(c, i));
        mp[mk(a, c)] = max(mp[mk(a, c)], mk(b, i));
        mp[mk(b, c)] = max(mp[mk(b, c)], mk(a, i));
    }

    if(sndIdx == -1){
        cout<<1<<endl;
        cout<<fstIdx + 1<<endl;
    }
    else{
        cout<<2<<endl;
        cout<<fstIdx + 1<<" "<<sndIdx + 1<<endl;
    }
    
    return 0;
}

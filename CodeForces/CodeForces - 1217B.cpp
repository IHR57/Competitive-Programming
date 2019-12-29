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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test, n;
    ll x;

    cin>>test;

    while(test--){
        cin>>n>>x;
        ll d, h;
        ll Max = -1, MaxD = -1;
        vector<ll> v;
        for(int i = 0; i < n; i++){
            cin>>d>>h;
            v.pb(d);
            MaxD = max(MaxD, d);
            if(d > h){
                if((d - h) > Max){
                    Max = d - h;
                }
            }
        }
        if(MaxD >= x){
            cout<<1<<endl;
            continue;
        }
        if(Max == -1){
            cout<<-1<<endl;
            continue;
        }
        sort(v.begin(), v.end());
        int low = 0, high = (x / Max) + 1, mid, ans = -1;
        while(low <= high){
            mid = (low + high + 1) >> 1;
            int idx = lower_bound(v.begin(), v.end(), (x - (1LL * mid * Max))) - v.begin();
            if(idx < v.size()){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        cout<<ans+1<<endl;

    }
    return 0;
}

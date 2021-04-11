//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], pref[MAX], suff[MAX];
ll cs[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test, n;

    cin>>test;

    while(test--){
        cin>>n;
        for(int i = 0; i <= n; i++){
            pref[i] = 0, suff[i] = 0;
            cs[i] = 0;
        }
        set<int> s;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            s.insert(arr[i]);
            pref[i+1] = s.size();
            cs[i+1] = cs[i] + arr[i];
        }
        s.clear();
        for(int i = n - 1; i >= 0; i--){
            s.insert(arr[i]);
            suff[i+1] = s.size();
        }

        vector<ii> vp;
        for(int i = 1; i < n; i++){
            ll l = i, r = n - i;
            ll rsum = (1LL * r * (r + 1)) >> 1LL;
            ll lsum = (1LL * l * (l + 1)) >> 1LL;
            if(pref[i] == i && cs[l] == lsum && (cs[n]-cs[n-r]) == rsum && suff[n-r+1] == r){
                vp.pb(mk((int) l, (int) r));
            }
        }

        cout<<vp.size()<<endl;
        for(int i = 0; i < vp.size(); i++){
            cout<<vp[i].ff<<" "<<vp[i].ss<<endl;
        }
    }

    return 0;
}

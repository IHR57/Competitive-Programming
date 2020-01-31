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

int Min[MAX];
bool isSpecial[MAX];

vector<int> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, val;

    cin>>n;

    vector<int> special;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        int m;
        cin>>m;
        Min[i] = INF;
        int Max = 0;
        bool foundSpecial = false;
        for(int j = 0; j < m; j++){
            cin>>val;
            if(val > Min[i]){
                foundSpecial = true;
            }
            Max = max(Max, val);
            Min[i] = min(Min[i], val);
        }
        if(!foundSpecial){
            v.pb(Max);
        }
        else{
            cnt++;
            isSpecial[i] = true;
        }
    }

    sort(v.begin(),v.end());

    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(isSpecial[i]){
            ans += 1LL * n;
            continue;
        }
        int x = Min[i];
        int idx = upper_bound(v.begin(), v.end(), x) - v.begin();
        //cout<<Min[i]<<" "<<idx<<endl;
        ans += 1LL * ((int) v.size() - idx);
        ans += 1LL * cnt;
    }

    cout<<ans<<endl;

    return 0;
}

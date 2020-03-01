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

bool compare(ii A, ii B)
{
    return A.ss > B.ss;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    set<int> s;

    cin>>n;

    vector<ii> arr(n);

    for(int i = 0; i < n; i++){
        cin>>arr[i].ff;
    }
    for(int i = 0; i < n; i++)
        cin>>arr[i].ss;

    sort(arr.begin(), arr.end());

    int cnt = 0;
    for(int i = 0; i < n ; i++){
        if(arr[i].ff > cnt){
            cnt = arr[i].ff;
            s.insert(arr[i].ff);
        }
        else{
            cnt++;
            s.insert(cnt);
        }
    }

    sort(arr.begin(), arr.end(), compare);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        set<int> :: iterator it;
        it = s.lower_bound(arr[i].ff);
        ans += 1LL * (*it - arr[i].ff) * arr[i].ss;
        s.erase(*it);
    }

    cout<<ans<<endl;
    

    return 0;
}

//Date: 16/12/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1.0)
#define INF 2147483647
#define MOD 1000000007
#define MAX 300005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool check(ll mask, ll pos) { return (bool) (mask & (1LL<<pos)); };
void Set(int mask, int pos) { mask = (mask | (1<<pos)); };

int arr[MAX], vis[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, neg = 0, idx, Min = INF;

    cin>>n;

    vector<int> zeroIdx;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] == 0){
            zeroIdx.pb(i);
            vis[i] = 1;
        }
        if(arr[i] < 0){
            neg++;
            if(abs(arr[i]) < Min){
                Min = abs(arr[i]);
                idx = i;
            }
        }
    }

    for(int i = 0; i < (int) zeroIdx.size() - 1; i++){
        cout<<1<<" "<<zeroIdx[i] + 1<<" "<<zeroIdx[i+1] + 1<<endl;
        cnt++;
    }

    if(neg & 1){
        if(zeroIdx.size()){
            cout<<1<<" "<<idx + 1<<" "<<zeroIdx[zeroIdx.size()-1] + 1<<endl;
            cnt++;
        }
        else{
            cout<<2<<" "<<idx + 1<<endl;
            cnt++;
        }
        vis[idx] = 1;
    }
    if(zeroIdx.size() && cnt < n - 1){
        cout<<2<<" "<<zeroIdx[zeroIdx.size()-1] + 1<<endl;
    }

    vector<int> v;
    for(int i = 0; i < n; i++){
        if(!vis[i])
            v.pb(i);
    }

    for(int i = 0; i < (int) v.size() - 1; i++){
        cout<<1<<" "<<v[i] + 1<<" "<<v[i+1] + 1<<endl;
    }

    return 0;
}
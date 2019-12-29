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

int arr[MAX];
vector<int> v[MAX], cs[MAX];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n,  k;
    ll Min = 1e14;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        int temp = arr[i];
        int x = 0;
        while(temp){
            v[temp].pb(x);
            x++;
            temp >>= 1;
        }
        v[0].pb(x);
    }

    for(int i = 0; i < MAX; i++){
        if(!v[i].empty())
            sort(v[i].begin(), v[i].end());
    }

    for(int i = 0; i < MAX; i++){
        if(v[i].size() < k)
            continue;
        ll s = 0;
        for(int j = 0; j < k; j++){
            s += (ll) v[i][j];
        }
        if(s < Min){
            Min = s;
        }
    }

    cout<<Min<<endl;

    return 0;
}

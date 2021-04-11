//Date: 21/03/2020
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
#define MAX 1005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int c[MAX], res[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n, m, d;

    cin>>n>>m>>d;

    int wood = 0;
    for(int i = 0; i < m; i++){
        cin>>c[i];
        wood += c[i];
    }

    int space = (m + 1) * (d - 1);

    if(wood < (n - space)){
        cout<<"NO"<<endl;
        return 0;
    }

    int req = n - wood;

    vector<int> v;
    for(int i = 1; i <= m + 1; i++){
        int rem = min(req, d - 1);
        if(req != 0)
            v.pb(rem);
        req -= rem;
    }

    cout<<"YES"<<endl;
    int j = 1;
    int idx = -1;
    for(int i = 0; i < v.size(); i++){
        for(int k = 1; k <= v[i]; k++){
            if(j <= n)
                res[j] = 0;
            j++;
        }
        for(int k = 0; k < c[i]; k++){
            idx = i;
            if(j <= n)
                res[j] = (i + 1);
            j++;
        }
    }


    for(int i = idx + 1; i < m; i++){
        for(int k = 1; k <= c[i]; k++){
            if(j <= n){
                res[j] = i + 1;
            }
            j++;
        }
    }

    for(int i = 1; i <= n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;

}

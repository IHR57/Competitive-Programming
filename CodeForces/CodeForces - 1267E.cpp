//Date: 28/03/2020
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
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int n, m, arr[105][105];
vector<ii> vp;

bool cmp(ii A, ii B)
{
    return A.ff > B.ff;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }

    vector<int> ans;
    int Min = 2e9;
    for(int i = 0; i < n - 1; i++){
        vp.clear();
        for(int j = 0; j < m; j++){
            int temp = arr[j][i] - arr[j][n-1];
            vp.pb(mk(temp, j));
        }

        sort(vp.begin(), vp.end(), cmp);

        int sum = 0;
        vector<int> tmp;
        for(int j = 0; j < m; j++){
            if(sum + vp[j].ff >= 0){
                sum += vp[j].ff;
            }
            else
                tmp.pb(vp[j].ss);
        }
        if((int) tmp.size() < Min){
            Min = tmp.size();
            ans = tmp;
        }

    }

    cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i] + 1<<" ";
    }
    cout<<endl;

    return 0;

}

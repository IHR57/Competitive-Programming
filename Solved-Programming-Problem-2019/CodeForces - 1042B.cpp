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
#define MAX 1000005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<ii> a, b;
int c[1005], pos[1005];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, costC = 1e9, cidx = -1;
    string str;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>c[i]>>str;
        for(int j = 0; j < str.size(); j++){
            if(str[j] == 'A')
                a.pb(mk(c[i], i));
            if(str[j] == 'B')
                b.pb(mk(c[i], i));
            if(str[j] == 'C'){
                if(c[i] < costC){
                    costC = c[i];
                    cidx = i;
                }
                pos[i] = 1;
            }
        }
    }

    if(a.empty() || b.empty() || cidx == -1){
        cout<<-1<<endl;
        return 0;
    }

    int ans = 1e9;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            int t;
            if(a[i].ss != b[j].ss){
                t = a[i].ff + b[j].ff;
                if(pos[a[i].ss] != 1 && pos[b[j].ss] != 1){
                    t += costC;
                }
            }
            else{
                t = a[i].ff;
                if(pos[a[i].ss] != 1)
                    t += costC;
            }
            ans = min(ans, t);
        }
    }

    cout<<ans<<endl;

    return 0;
}

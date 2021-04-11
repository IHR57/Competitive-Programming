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
#define MAX 2005
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
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;

    cin>>n;

    vector<long double> v;

    ll sum = 0;
    long double ans = 0.0;
    queue<ll> q;
    int cnt = 1;
    ll last;

    for(int i = 0; i < n; i++) {
        int type;
        ll num;
        cin>>type;
        if(type == 1) {
            cin>>num;
            q.push(num);
            last = num;
        }
        else if(type == 2){
            while(!q.empty()) {
                ll u = q.front();
                if(u < (long double) (sum + last) / cnt) {
                    sum += u;
                    cnt++;
                    q.pop();
                }
                else {
                    break;
                }
            }
            ans = last - (long double) (sum + last) / cnt;
            cout<<fixed<<setprecision(8);
            cout<<ans<<endl;
        }
    }

    return 0;
}
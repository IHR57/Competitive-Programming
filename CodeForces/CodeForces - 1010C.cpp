//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000009
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

int arr[MAX], mark[MAX];
bool dp[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k;

    cin>>n>>k;

    int g = 0;
    set<int> s;
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        g = __gcd(arr[i], g);
    }

    if(g == 1) {
        cout<<k<<endl;
        for(int i = 0; i < k; i++) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else {
        for(long long i = 0, x = 0; i < k; i++, x += g) {
            if(s.count(x % k))
                break;
            s.insert(x % k);
        }
        cout<<s.size()<<endl;
        for(set<int> :: iterator it = s.begin(); it != s.end(); it++) {
            cout<<(*it)<<" ";
        }
        cout<<endl;
    }

    return 0;
}
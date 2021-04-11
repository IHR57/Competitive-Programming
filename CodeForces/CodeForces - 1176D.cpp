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
#define MAX 2750132
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

bool mark[MAX];
int lpf[MAX]; // lpf - lowest prime factor
map<int, int> mp;
vector<int> primes;
int arr[MAX];

void genSieve() 
{
    for(int i = 2; i < MAX; i++) {
        if(!mark[i]) {
            primes.pb(i);
            lpf[i] = i;
            for(int j = 2 * i; j < MAX; j += i) {
                mark[j] = 1;
                if(!lpf[j])
                    lpf[j] = i;
            }
            mp[i] = primes.size();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    genSieve();
    int n;

    cin>>n;

    multiset<int> ms;
    for(int i = 0; i < (2 * n); i++) {
        cin>>arr[i];
        ms.insert(arr[i]);
    }

    vector<int> ans;

    while(!ms.empty()) {
        int tx = *(--ms.end());
        int tt;
        if(!mark[tx]) {
            tt = mp[tx];
            ans.pb(tt);
        }
        else {
            ans.pb(tx);
            tt = tx / lpf[tx];
        }

        //cout<<tx<<" "<<tt<<endl;

        ms.erase(ms.find(tx));
        ms.erase(ms.find(tt));
    }

    for(int i = 0; i < n; i++) {
        cout<<ans[i]<<" ";
    }

    cout<<endl;

    
    return 0;
}



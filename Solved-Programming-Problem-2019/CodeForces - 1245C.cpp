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

ll fib[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;

    cin>>str;

    int n = str.size();

    fib[0] = 1, fib[1] = 1;
    for(int i = 2; i <= n; i++){
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }

    ll ans = 1;

    char prev = '#';
    int cnt = 1;
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(str[i] == 'm' || str[i] == 'w'){
            flag = true;
            break;
        }
        if(str[i] == prev){
            cnt++;
        }
        else{
            if(prev == 'u' || prev == 'n')
                if(cnt >= 2)
                    ans = (1LL * ans * fib[cnt]) % MOD;
            prev = str[i];
            cnt = 1;
        }
    }
    if(prev == 'u' || prev == 'n')
        if(cnt >= 2)
            ans = (1LL * ans * fib[cnt]) % MOD;

    if(flag){
        cout<<0<<endl;
        return 0;
    }
    cout<<ans<<endl;

    return 0;
}

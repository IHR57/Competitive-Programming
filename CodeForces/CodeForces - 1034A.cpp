//Date: 25/12/19
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 15000005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

bool mark[MAX];
int primes[MAX/10], cnt[MAX], counter = 0;
int arr[300005];

void genSieve()
{
    int limit = sqrt(MAX + 1);
    mark[1] = 1;
    for(int i = 4; i < MAX; i += 2){
        mark[i] = 1;
    }

    primes[counter++] = 2;

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(ll j = 1LL * i * i; j < MAX; j += i * 2){
                    mark[j] = 1;
                }
            }
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
    //cout<<counter<<endl;

    cin>>n;

    int g = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        g = __gcd(g, arr[i]);
    }

    for(int i = 0; i < n; i++){
        arr[i] /= g;
        cnt[arr[i]]++;
    }

    if(cnt[1] == n){
        cout<<-1<<endl;
        return 0;
    }

    int Mx = 0;
    for(int i = 0; i < counter; i++){
        int res = 0;
        for(int j = primes[i]; j < MAX; j += primes[i]){
            res += cnt[j];
        }
        Mx = max(Mx, res);
    }
    cout<<n - Mx<<endl;

    return 0;
}

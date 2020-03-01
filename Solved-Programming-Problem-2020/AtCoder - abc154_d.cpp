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

int cs[MAX], arr[MAX];
double prob[1005];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;

    cin>>n>>k;

    for(int i = 1; i <= 1000; i++){
        double res = 0;
        for(int j = 1; j <= i; j++){
            res += (double) j * (1 / (double) i);
        }
        prob[i] = res;
    }

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        cs[i+1] = cs[i] + arr[i];
    }

    int Max = 0, idx;
    for(int i = 0; i <= n - k; i++){
        int tx = cs[i+k] - cs[i];
        if(tx > Max){
            Max = tx;
            idx = i;
        }
    }

    double ans = 0;
    for(int i = idx; i < idx + k; i++){
        ans += prob[arr[i]];
    }

    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;

    return 0;
}

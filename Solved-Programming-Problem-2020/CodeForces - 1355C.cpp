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
 
ll cs[MAX * 10];
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int a, b, c, d;
    ll ans = 0;
 
    cin>>a>>b>>c>>d;
 
    for(int i = a; i <= b; i++) {
        cs[i + b]++;
        cs[i + c + 1]--;
    }
 
    int M = MAX * 10;
    for(int i = 1; i < M; i++)
        cs[i] += cs[i-1];
    for(int i = 1; i < M; i++)
        cs[i] += cs[i-1];
 
    for(int i = c; i <= d; i++) {
        ans += cs[M-1] - cs[i];
    }
 
    cout<<ans<<endl;
 
    return 0;
}
 

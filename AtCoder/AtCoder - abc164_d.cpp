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

int pow10[200005];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string str;

    cin>>str;

    vector<int> cnt(2020, 0);
    int n = str.size();
    cnt[0] = 1;


    pow10[0] = 1;
    for(int i = 1; i <= n; i++) {
        pow10[i] = (pow10[i-1] * 10) % 2019;
    }
    
    int ans = 0, rem = 0;
    for(int i = 0; i < n; i++) {
        rem = (rem * 10 + (str[i]-'0')) % 2019;
        int temp = (rem * pow10[n-i-1]) % 2019;
        ans += cnt[temp];
        cnt[temp]++;
    }

    cout<<ans<<endl;

    return 0;
}
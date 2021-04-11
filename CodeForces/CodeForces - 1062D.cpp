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

ll ans[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n;

    cin>>n;

    ans[2] = ans[3] = 0;
    for(int i = 4; i <= n; i++) {
        ll temp = 0;
        ans[i] = ans[i-1];
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) {
                temp += 1LL * (i / j) * 4;
                if((i / j) != j) {
                    temp += 1LL * j * 4;
                }
            }
        }
        ans[i] += temp;
    }

    cout<<ans[n]<<endl;

    return 0;
}
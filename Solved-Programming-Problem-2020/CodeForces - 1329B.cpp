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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    
    int d, m, test;

    cin>>test;

    while(test--){

        cin>>d>>m;

        ll res = 1;
        for(int i = 0; i < 30; i++){
            if(d < (1<<i))
                break;
            ll temp = min((1<<(i + 1)) - 1, d) - (1<<i) + 2;
            res = (1LL * res * temp) % m;
        }
        res--;
        res = (res + m) % m;

        cout<<res<<endl;
    }

    return 0;
}
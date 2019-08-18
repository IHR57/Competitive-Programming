//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define debug (printf("PINK FLOYD:)\n"))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define EPS 1e-8
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

int ans[2*MAX];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    if(n % 2 == 0){
        cout<<"NO"<<endl;
        return 0;
    }

    priority_queue<int> pq;

    for(int i = 3; i <= 2 * n; i++)
        pq.push(i);
    ans[1] = 1, ans[n+1] = 2;
    for(int i = 2; i <= n; i++){
        int u = pq.top();
        pq.pop();
        int v = pq.top();
        pq.pop();
        //cout<<u<<" "<<v<<endl;
        if(i % 2 == 0){
            ans[i] = u, ans[n+i] = v;
        }
        else{
            ans[i] = v, ans[n+i] = u;
        }
    }

    cout<<"YES"<<endl;
    for(int i = 1; i <= 2 * n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}

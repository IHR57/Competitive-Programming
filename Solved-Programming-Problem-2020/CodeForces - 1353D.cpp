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

bool compare(ii A, ii B) {
    if(A.ff == B.ff) 
        return A.ss < B.ss;
    return A.ff > B.ff;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int test, n;
 
    cin>>test;

    while(test--){
        cin>>n;

        priority_queue<ii> pq;
 
        vector<int> res(n + 1, 0);

        pq.push(mk(n, 1));
        vector<ii> vp;

        int cnt = 1;
        while(!pq.empty()) {
            ii x = pq.top();
            if(x.ff >= 1)
                vp.push_back(x);
            int m = (x.ss + x.ss + x.ff - 1) >> 1;
            int left = (x.ff >> 1) - (x.ff % 2 == 0);
            int right = (x.ff >> 1);
            pq.pop();

            if(x.ff > 1){
                pq.push(mk(left, x.ss));
                pq.push(mk(right, m + 1));
            }
        }

        sort(vp.begin(), vp.end(), compare);

        for(int i = 0; i < vp.size(); i++){
            int m = (vp[i].ss + vp[i].ss + vp[i].ff - 1) >> 1;
            if(!res[m])
                res[m] = cnt++;
        }

        for(int i = 1; i <= n; i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }

    return 0;
}
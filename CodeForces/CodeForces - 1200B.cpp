//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mp make_pair
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

int h[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k, test;

    cin>>test;

    while(test--){
        cin>>n>>m>>k;
        for(int i = 0; i < n; i++){
            cin>>h[i];
        }

        bool flag = true;
        for(int i = 0; i < n - 1; i++){
            if(h[i] >= h[i+1]){
                m += min(h[i], h[i] - (h[i+1] - k));
            }
            else{
                int req = (h[i+1] - h[i]);
                if(req <= k){
                    m += min(h[i], h[i] - (h[i+1] - k));
                }
                else{
                    int t = (h[i+1] - k - h[i]);
                    if(t > m){
                        flag = false;
                        break;
                    }
                    m -= t;
                }
            }
        }
        (flag) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
    return 0;
}

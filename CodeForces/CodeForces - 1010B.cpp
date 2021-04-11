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

bool mark[35];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int m, n, t;

    cin>>m>>n;

    for(int i = 0; i < n; i++) {        // lie detection
        cout<<(1)<<endl;
        fflush(stdout);
        cin>>t;
        if(t == 0 || t == -2)
            return 0;
        if(t == -1) {
            mark[i] = true;
        }
    }

    int low = 1, high = m, mid, ans, pos = 0;

    while(low <= high) {
        mid = (low + high + 1) >> 1;
         cout<<mid<<endl;
         fflush(stdout);
        cin>>t;

        if(t == 0 || t == -2)
            break;

        if(mark[pos])
             t = -t;

        if(t == 1) {
            low = mid + 1;
        }
        else
            high = mid - 1;
        pos = (pos + 1) % n;
    }



 
    return 0;
}
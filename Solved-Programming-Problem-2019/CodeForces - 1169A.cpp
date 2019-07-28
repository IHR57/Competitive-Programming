#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define dis(x1, y1, x2, y2) ((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2))
#define debug (printf("PINK FLOYD:)\n"))
#define iosflags (cout<<setiosflags(ios::fixed)<<setprecision(8))
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
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a, x, b, y;

	cin>>n>>a>>x>>b>>y;
	while(true){
        if(a == b){
            cout<<"YES"<<endl;
            return 0;
        }
        if(a == x || b == y){
            break;
        }
        a = a + 1;
        b = b - 1;
        if(a > n)
            a = 1;
        if(b <= 0)
            b = n;
	}

	cout<<"NO"<<endl;

    return 0;
}

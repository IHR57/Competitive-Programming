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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, a[1005], b[1005];
	set<int> s1, s2;
	cin>>n;

	for(int i = 0; i < n; i++){
        cin>>a[i];
        s1.insert(a[i]);
	}
	cin>>m;
	for(int i = 0; i < m; i++){
        cin>>b[i];
        s2.insert(b[i]);
	}

	for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            int temp = a[i] + b[j];
            if(!s1.count(temp) && !s2.count(temp)){
                cout<<a[i]<<" "<<b[j]<<endl;
                return 0;
            }
        }
	}
    return 0;
}

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
#define MAX 50005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int rowSum[MAX], colSum[MAX];
set<int> s[MAX];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q;
	string str;

	cin>>q;
    while(q--){
        int n, m;

        mem(rowSum, 0);
        mem(colSum, 0);
        cin>>n>>m;

        for(int i = 0; i < n; i++){
            cin>>str;
            for(int j = 0; j < m; j++){
                if(str[j] == '*'){
                    rowSum[i]++;
                    colSum[j]++;
                }
                else{
                    s[i].insert(j);
                }
            }
        }

        int ans = 1e9;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int need = (n + m) - (rowSum[i] + colSum[j]);
                if(s[i].find(j) != s[i].end()){
                    need--;
                }
                ans = min(ans, need);
            }
        }

        cout<<ans<<endl;
        for(int i = 0; i < n; i++)
            s[i].clear();
    }
    return 0;
}

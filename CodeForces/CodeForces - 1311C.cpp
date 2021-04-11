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

int cs[MAX][26];
int pos[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test;

    cin>>test;

    while(test--){
        int n, m;
        cin>>n>>m;
        string str;
        cin>>str;

        for(int i = 0; i < m; i++){
            cin>>pos[i];
        }

        pos[m] = n;
        m++;

        sort(pos, pos + m);

        for(int i = 0; i < n; i++){
            int id = str[i] - 'a';
            for(int j = 0; j < 26; j++){
                cs[i+1][j] = cs[i][j] + (id == j);
            }
        }

        int res[26] = {0};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < 26; j++){
                res[j] += cs[pos[i]][j];
            }
        }

        for(int i = 0; i < 26; i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;

        for(int i = 0; i <= n; i++){
            for(int j = 0; j < 26; j++){
                cs[i][j] = 0;
            }
        }
    }
    return 0;
}

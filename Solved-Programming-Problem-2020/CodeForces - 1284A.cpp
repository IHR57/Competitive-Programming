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

    int n, m;

    vector<string> vs1, vs2;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        string str;
        cin>>str;
        vs1.pb(str);
    }

    for(int i = 0; i < m; i++){
        string str;
        cin>>str;
        vs2.pb(str);
    }

    int q;

    cin>>q;

    for(int i = 0; i < q; i++){
        int x;
        cin>>x;
        x--;
        string a, b;
        a = vs1[x%n];
        b = vs2[x%m];

        cout<<a+b<<endl;
    }
    return 0;
}

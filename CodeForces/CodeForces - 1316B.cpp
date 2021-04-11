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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, test;
    string str;

    cin>>test;

    while(test--) {
        cin>>n;
        cin>>str;

        vector<pair<string, int> > vp;

        for(int i = 0; i < n; i++) {
            string temp1 = str.substr(i, n - i);
            string temp2 = str.substr(0, i);
            if((n - i) % 2 != 0)
                reverse(temp2.begin(), temp2.end());
            vp.pb(mk(temp1 + temp2, i));
        }

        sort(vp.begin(), vp.end());

        cout<<vp[0].ff<<endl;
        cout<<vp[0].ss + 1<<endl;
    }

    return 0;
}


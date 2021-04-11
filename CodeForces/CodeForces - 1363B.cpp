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
    string str;
    int test;

    cin>>test;

    while(test--) {
        cin>>str;
        int n = str.size();
        vector<int> pref(n + 1, 0), suff(n + 2, 0);

        for(int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + (str[i] == '1');
        }
        for(int i = n - 1; i >= 0; i--) {
            suff[i+1] = suff[i+2] + (str[i] == '1');
        }

        int ans = min(pref[n], n - pref[n]);

        for(int i = 1; i <= n; i++) {
            int temp = pref[i] + ((n - i) - suff[i+1]);
            ans = min(ans, temp);
        }

        for(int i = 1; i <= n; i++) {
            int temp = (i - pref[i]) + suff[i+1];
            ans = min(ans, temp);
        }

        cout<<ans<<endl;
    }

    return 0;
}


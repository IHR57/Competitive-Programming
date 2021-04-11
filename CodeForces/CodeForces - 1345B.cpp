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

    vector<int> v;
    v.pb(0);
    v.pb(2);

    for(int  i = 2; ; i++) {
        int temp = (i * (i + 1)) + (i * (i - 1)) / 2;
        if(temp > 1e9)
            break;
        v.pb(temp);
    }

    int test, n;

    cin>>test;

    while(test--) {
        cin>>n;

        int cnt = 0;

        while(n >= 2) {
            int idx = upper_bound(v.begin(), v.end(), n) - v.begin();
            idx--;
            n -= v[idx];
            cnt++;
        }

        cout<<cnt<<endl;
    }
    return 0;
}


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

    int test, a, b, c;

    cin>>test;

    while(test--){
        int n;
        cin>>a>>b>>c>>n;
        int Min = min(min(a, b), c);
        a -= Min, b -= Min, c -= Min;
        int Max = max(max(a, b), c);
        //cout<<a<<" "<<b<<" "<<c<<endl;
        int t = (Max - a);
        n -= t;
        t = (Max - b);
        n -= t;
        t = (Max - c);
        n -= t;
        if(n >= 0 && n % 3 == 0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}

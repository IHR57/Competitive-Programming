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

bool Check(int a, int b)
{
    if(a >= 1 && b >= 1)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, a, b, c;

    cin>>test;

    while(test--){
        cin>>a>>b>>c;
        int ans = 0;
        if(a){
            ans++;
            a -= 1;
        }
        if(b){
            ans++;
            b-=1;
        }
        if(c){
            ans++;
            c-=1;
        }

        if(a < b)
            swap(a, b);
        if(a < c)
            swap(a, c);
        if(b < c)
            swap(b, c);

        if(Check(a, b))
            a -= 1, b -= 1, ans++;
        if(Check(a, c))
            a -= 1, c -= 1, ans++;
        if(Check(b, c))
            b -= 1, c -= 1, ans++;
        if(a >= 1 && b >= 1 && c >= 1)
            ans++;

        cout<<ans<<endl;
    }

    return 0;
}

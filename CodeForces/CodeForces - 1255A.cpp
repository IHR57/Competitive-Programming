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
    int a, b;

    int test;

    cin>>test;

    while(test--){
        cin>>a>>b;
        if(a > b)
            swap(a, b);

        int t = (b - a) / 5;
        int x = (b - a) % 5;

        int ans;
        if(x == 0 || x == 1 || x == 2){
            ans = t + 1;
            if(x == 0)
                ans--;
        }
        else{
            ans = t + 2;
        }

        cout<<ans<<endl;
    }

    return 0;
}

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
    int n, k, test;

    cin>>test;

    while(test--){
        cin>>n>>k;
        int sum = 1, x = 0;
        while(sum + x <= k){
            sum += x;
            x++;
        }

        int firstPos = n - x;
        for(int i = 1; i < firstPos; i++)
            cout<<"a";
        cout<<"b";
        int rem = n - (k - sum);
        for(int i = firstPos + 1; i < rem; i++){
            cout<<"a";
        }
        cout<<"b";
        for(int i = rem + 1; i <= n; i++)
            cout<<"a";
        cout<<endl;

    }

    return 0;
}

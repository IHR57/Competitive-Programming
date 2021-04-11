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

int arr[205], n, x;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test;

    cin>>test;

    while(test--){
        cin>>n>>x;
        set<int> s;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            s.insert(arr[i]);
        }

        int ans = 0;
        for(int i = 1; ; i++){
            if(x == 0 && !s.count(i))
                break;
            if(!s.count(i)){
                x--;
            }
            ans = i;
        }

        cout<<ans<<endl;
    }
    return 0;
}

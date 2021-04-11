//Date: 14/01/20
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int test;

    cin>>test;

    while(test--){
        int n;
        cin>>n;

        multiset<int> ms;
        set<int> s;
        vector<int> v;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            ms.insert(arr[i]);
            s.insert(arr[i]);
        }

        set<int> :: iterator it;
        for(it = s.begin(); it != s.end(); it++){
            v.pb(ms.count(*it));
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        int ans = 0;
        ans += v[0];
        int prev = v[0];
        for(int i = 1; i < v.size(); i++){
            if(v[i] < prev){
                prev = v[i];
                ans += v[i];
            }
            else{
                if(prev <= 0)
                    break;
                ans += (prev - 1);
                prev = (prev - 1);
            }
        }

        cout<<ans<<endl;
    }




    return 0;
}
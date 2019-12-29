//Date: 26/12/19
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 15000005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int mark[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    ll a, b, low = 1, high = 1e5, mid, ans = -1;

    cin>>a>>b;

    while(low <= high){
        mid = (low + high + 1) >> 1;
        if((mid * (mid + 1)) / 2 <= (a + b)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    //cout<<ans<<endl;
    if(ans == -1){
        cout<<0<<endl;
        cout<<0<<endl;
        return 0;
    }

    int cnt = 0;
    int sum = 0;
    for(int i = ans; i >= 1; i--){
        if(sum + i <= a){
            sum += i;
            cnt++;
            mark[i] = 1;
        }
        else{
            mark[a-sum] = 1;
            if(a - sum != 0)
                cnt++;
            break;
        }
    }
    cout<<cnt<<endl;
    for(int i = 1; i <= ans; i++){
        if(mark[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl<<ans - cnt<<endl;
    for(int i = 1; i <= ans; i++){
        if(!mark[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;

    return 0;
}

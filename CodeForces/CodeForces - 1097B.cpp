#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 1e17
#define MOD 1000000007
#define MAX 55
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[20];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;

    cin>>n;
    for(int i = 0; i <  n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < (1 << n); i++){
        int d = 0;
        for(int j = 0; j < n; j++){
            if(check(i, j)){
                d += arr[j];
                if(d >= 360)
                    d -= 360;
            }
            else{
                d -= arr[j];
                if(d < 0)
                    d += 360;
            }
        }
        if(d == 0){
            cout<<"YES"<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;
    
    return 0;
}

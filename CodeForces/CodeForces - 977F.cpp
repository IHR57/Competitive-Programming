//Date: 01/02/2020
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], dp[MAX], idx[MAX], ans[MAX];

void print(int x)
{
    if(ans[x] == x){
        cout<<x + 1<<" ";
        return;
    }
    print(ans[x]);
    cout<<x + 1<<" ";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int x = 1;
    map<int, int> mp;

    for(int i = 0; i < n; i++)
        ans[i] = i;

    for(int i = 0; i < n; i++){
        dp[i] = 1;
        if(mp[arr[i]] == 0){
            mp[arr[i]] = x++;
            idx[mp[arr[i]]] = i;
        }
        idx[mp[arr[i]]] = i;
        if(mp.count(arr[i] - 1)){
            dp[i] = dp[idx[mp[arr[i]-1]]] + 1;
            ans[i] = idx[mp[arr[i]-1]];
        }
    }

    int Mx = 0, ind;
    for(int i = 0; i < n; i++){
        if(dp[i] > Mx){
            Mx = dp[i];
            ind = i;
        }
    }

    cout<<Mx<<endl;
    print(ind);


    return 0;
}
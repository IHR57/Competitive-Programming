/*
Template for vjudge.net

    Author: Iqbal Hossain Rasel
    CodeForces: The_Silent_Man
    AtCoder   : IHR57
    TopCoder  : IHR57

*/
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
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], vis[MAX], a[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;

    cin>>n>>m;

    for(int i = 1; i <= m; i++){
        cin>>arr[i];
    }

    memset(a, -1, sizeof(a));
    for(int i = 1; i < m; i++){
        int t;
        if(arr[i+1] < arr[i]){
            t = (n - (arr[i] - arr[i+1]));
        }
        else
            t = (arr[i+1] - arr[i]);
        if(arr[i] == arr[i+1])
            t = n;
        if(a[arr[i]] == -1){
            if(vis[t]){
                cout<<-1<<endl;
                return 0;
            }
            a[arr[i]] = t;
            vis[t] = 1;
        }
        else{
            if(a[arr[i]] != t){
                cout<<-1<<endl;
                return 0;
            }
        }
    }

    int cnt = 0, c = 0;
    vector<int> v;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cnt++;
            v.pb(i);
        }
        if(a[i] == -1)
            c++;
    }

    int k = 0;
    if(cnt == c){
        for(int i = 1; i <= n; i++){
            if(a[i] == -1){
                a[i] = v[k];
                k++;
            }
            cout<<a[i]<<" ";
        }
    }
    else{
        cout<<-1<<endl;
        return 0;
    }

    return 0;
}

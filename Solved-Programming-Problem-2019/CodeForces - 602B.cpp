//Date: 22/09/19
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
#define MAX 100005
using namespace std;
 
typedef unsigned long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}
 
int a[MAX], pos[MAX];

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
        cin>>a[i];
    }

    int Max = a[0], Min = a[0], ans = 1, temp = 1;
    pos[a[0]] = 0;

    for(int i = 1; i < n; i++){
        Max = max(Max, a[i]);
        Min = min(Min, a[i]);
        if(Max - Min >= 2){
            if(a[i] == Max){
                ans = max(ans, i - pos[Min]);
                temp = i - pos[Min];
                Min = Min + 1;
            }
            if(a[i] == Min){
                ans = max(ans, i - pos[Max]);
                temp = (i - pos[Max]);
                Max = Max - 1;
            }
        }
        else{
            temp++;
            ans = max(ans, temp);
        }
        pos[a[i]] = i;
    }

    cout<<ans<<endl;

    return 0;
}
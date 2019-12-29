//Problem ID: CodeForces - 1176C (Lose It)
//Programmer: IQBAL HOSSAIN     Description: DP/Greedy
//Date: 23/08/19
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 5000005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

set<int> s;
int arr[MAX], cnt[105];

void solve(int a, int b)
{
    if(s.count(b)){
        s.insert(a);
        cnt[a]++;
        cnt[b]--;
        if(cnt[b] <= 0)
            s.erase(b);
    }
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

    for(int i = 0; i < n; i++){
        if(arr[i] == 4){
            s.insert(arr[i]);
            cnt[arr[i]]++;
        }
        else if(arr[i] == 8)
            solve(8, 4);
        else if(arr[i] == 15)
            solve(15, 8);
        else if(arr[i] == 16)
            solve(16, 15);
        else if(arr[i] == 23)
            solve(23, 16);
        else if(arr[i] == 42)
            solve(42, 23);
    }

    int ans = n - (6 * cnt[42]);

    cout<<ans<<endl; 

    return 0;
}

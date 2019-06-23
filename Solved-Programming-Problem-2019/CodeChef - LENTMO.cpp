//Problem ID: CodeChef - LENTMO (Lent Money)
//Programmer: IQBAL HOSSAIN     Description: Math/Greedy
//Date: 12/06/19
//Problem Link: https://www.codechef.com/JUNE19A/problems/LENTMO
#include <bits/stdc++.h>
#define MAX 10005
#define MOD 1000000007
#define INF 1e9
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
int arr[MAX];
int n, k, visited[MAX];
ll cs[MAX];

bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

void solve(int i, int j)
{
    if(visited[j])
        return;

    cout<<i<<" "<<j<<endl;
    visited[j] = 1;

    int x = min(k, i);
    for(int m = 0; m <= x; m++){
        if((k - m) > j)
            continue;
        int tempi = i - m + (k - m);
        int tempj = j - (k - m) + m;
        if(!visited[tempj]){
            //cout<<tempi<<" "<<tempj<<endl;
            solve(tempi, tempj);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, x;
    ll sum;
    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        ll sum = 0;
        vector<int> v;
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            sum += (ll) arr[i];
        }
        scanf("%d %d", &k, &x);
        for(int i = 0; i < n; i++){
            v.push_back((arr[i] ^ x) - arr[i]);
        }
        memset(visited, 0, sizeof(visited));

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        cs[0] = (ll) v[0];
        for(int i = 1; i < v.size(); i++){
            cs[i] = cs[i-1] + (ll) v[i];
        }

        //cout<<"Hey: Finished"<<endl;
        ll Max = sum;
        //solve(n - k, k);
        if(k == n){
            Max = max(Max, sum + cs[n-1]);
            printf("%lld\n", Max);
            continue;
        }
        for(int i = 1; i <= n; i++){
            if(k % 2 != 0 || (k % 2 == 0 && i % 2 == 0)){
                ll temp = sum + cs[i-1];
                Max = max(Max, temp);
            }
        }

        printf("%lld\n", Max);
        v.clear();
        
    }    

    return 0;
}

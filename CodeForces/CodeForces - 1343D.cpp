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
#define MAX 300005
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}
 
int arr[MAX];
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, n, k;
 
    cin>>test;
 
    while(test--){
        cin>>n>>k;
 
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        vector<int> cnt(2 * k + 2);
 
        for(int i = 0; i < n / 2; i++){
            int sum = arr[i] + arr[n-i-1];
            cnt[sum]++;
        }
 
        vector<int> pref(2 * k + 2);
 
        for(int i = 0; i < n / 2; i++){
            pref[min(arr[i], arr[n-i-1])+1]++;
            pref[max(arr[i], arr[n-i-1])+k+1]--;
        }
 
        for(int i = 1; i < 2 * k + 2; i++)
            pref[i] += pref[i-1];
 
 
        int ans = INF;
        for(int i = 2; i <= 2 * k; i++){
            int temp = (pref[i] - cnt[i]) + (n / 2 - pref[i]) * 2;
            ans = min(ans, temp);
        }
 
        cout<<ans<<endl;
    }
    return 0;
}
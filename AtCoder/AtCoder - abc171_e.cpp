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
#define MAX 200005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], cnt[32];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;

    cin>>n;
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        for(int j = 0; j < 31; j++) {
            if(check(arr[i], j))
                cnt[j]++;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 31; j++) {
            if(check(arr[i], j))
                cnt[j]--;
        }

        int res = 0;
        for(int j = 0; j < 31; j++) {
            if(cnt[j] & 1) {
                res += (1<<j);
            }
        }
        ans[i] = res;
        for(int j = 0; j < 31; j++) {
            if(check(arr[i], j))
                cnt[j]--;
        }
    }

    for(int i = 0; i < n - 1; i++)
        cout<<ans[i]<<" ";
    cout<<ans[n-1]<<endl;

    return 0;
}

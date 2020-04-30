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
#define MAX 500005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll arr[MAX], pref[MAX], suff[MAX], ta[MAX], tb[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }

    int top = 0;
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i-1];
        int cnt = 1;
        while(top > 0 && ta[top] >= arr[i]){
            pref[i] += 1LL * (ta[top] - arr[i]) * tb[top];
            cnt += tb[top];
            top--;
        }
        top++;
        ta[top] = arr[i];
        tb[top] = cnt;
    }

    top = 0;
    for(int i = n; i >= 1; i--){
        suff[i] = suff[i+1];
        int cnt = 1;
        while(top > 0 && ta[top] >= arr[i]) {
            suff[i] += 1LL * (ta[top] - arr[i]) * tb[top];
            cnt += tb[top];
            top--;
        }
        top++;
        ta[top] = arr[i];
        tb[top] = cnt;
    }

    int idx = 1;
    for(int i = 2; i <= n; i++){
        if(pref[i] + suff[i] < pref[idx] + suff[idx]){
            idx = i;
        }
    }

    for(int i = idx - 1; i >= 1; i--){
        arr[i] = min(arr[i], arr[i+1]);
    }
    for(int i = idx + 1; i <= n; i++){
        arr[i] = min(arr[i], arr[i-1]);
    }

    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}

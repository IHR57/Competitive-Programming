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

int arr[MAX], n, k;
int mark[MAX];

int check(int start)
{
    int lim = (start == 0) ? ((k + 1) >> 1) : (k >> 1);
    int low = 1, high = 1e9, mid, ans = INF;

    while(low <= high) {
        mid = (low + high + 1) >> 1;
        int prev = -1, cnt = 0;
        for(int i = start; i < n; i++) {
            if(arr[i] <= mid) {
                if(start == 0 && (k % 2 == 0) && i == n - 1)
                    continue;
                if(start == 1 && (k & 1) && i == n - 1)
                    continue;
                if(prev == -1) {
                    prev = i;
                    cnt++;
                }
                else {
                    if(prev != i - 1) {
                        cnt++;
                        prev = i;
                    }
                }
            }
        }
        if(cnt >= lim) {
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>n>>k;

    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    int ans = check(0);
    //cout<<ans<<endl;
    ans = min(ans, check(1));

    cout<<ans<<endl;

    return 0;
}


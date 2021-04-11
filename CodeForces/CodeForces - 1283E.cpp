//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 998244353
#define MAX 400005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], counter[MAX], vis[MAX];

int main()
{
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;

    scanf("%d",  &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        counter[arr[i]]++;
        vis[arr[i]] = 1;
    }    

    sort(arr, arr + n);

    int ansMin = 0, ansMax = 0;
    int cnt = 1, tot = 1, st = arr[0], last = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] - arr[i-1] <= 1) {
            cnt += (arr[i] - arr[i-1] == 1);
            last = arr[i];
            tot += 1;
        }
        else {
            if(tot > cnt) {
                if(vis[st-1] == 0) {
                    vis[st-1] = 1;
                    tot -= 1;
                }
                if(tot > cnt)
                    if(vis[last + 1] == 0) {
                        vis[last+1] = 1;
                        tot -= 1;
                    }
            }
            cnt = 1;
            tot = 1;
            st = last = arr[i];
        }
    }

    if(tot > cnt) {
        if(vis[st-1] == 0) {
            vis[st-1] = 1;
            tot -= 1;
        }
    }
    if(tot > cnt) {
        if(vis[last + 1] == 0) {
            vis[last+1] = 1;
            tot -= 1;
        }
    }

    for(int i = 0; i <= n + 1; i++) {
        ansMax += (vis[i] == 1);
    }

    for(int i = 1; i <= n; i++) {
        if(counter[i]) {
            ansMin++;
            i += 2;
        }
    }

    printf("%d %d\n", ansMin, ansMax);

    return 0;
}
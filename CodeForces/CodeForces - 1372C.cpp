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

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test;

    cin>>test;

    while(test--) {
        int n;
        cin>>n;

        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            cin>>arr[i];
            if(arr[i] == i) {
                cnt++;
            }
        }
        if(cnt == n) {
            cout<<0<<endl;
            continue;
        }

        if(cnt == 0) {
            cout<<1<<endl;
            continue;
        }
        if(arr[1] == 1 && arr[n] == n) {
            int leftIdx = 0, rightIdx = 0;
            for(int i = 1; i <= n; i++) {
                if(arr[i] != i) {
                    leftIdx = i;
                    break;
                }
            }

            for(int i = n; i >= 1; i--) {
                if(arr[i] != i) {
                    rightIdx = i;
                    break;
                }
            }

            bool flag = true;
            for(int i = leftIdx; i <= rightIdx; i++) {
                if(arr[i] == i) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cout<<1<<endl;
                continue;
            }
        }
        if(arr[1] == 1) {
            bool flag = true;
            int idx;
            for(int i = 2; i <= n; i++) {
                if(arr[i] != i) {
                    idx = i;
                    break;
                }
            }
            for(int i = idx; i <= n; i++) {
                if(arr[i] == i) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                cout<<1<<endl;
                continue;
            }
        }

        if(arr[n] == n) {
            bool flag = true;
            int idx;
            for(int i = n - 1; i >= 1; i--) {
                if(arr[i] != i) {
                    idx = i;
                    break;
                }
            }

            for(int i = idx; i >= 1; i--) {
                if(arr[i] == i) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                cout<<1<<endl;
                continue;
            }
        }

        cout<<2<<endl;
    }

    return 0;
}



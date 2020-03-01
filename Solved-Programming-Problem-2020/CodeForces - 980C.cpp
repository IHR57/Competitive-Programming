//Date: 01/02/2020
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MAX 100005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int ans[MAX], arr[MAX], isHead[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int hasAssigned[260];
    for(int i = 0; i < 256; i++)
        hasAssigned[i] = -1;

    for(int i = 0; i < n; i++){
        if(hasAssigned[arr[i]] != -1){
            ans[i] = hasAssigned[arr[i]];
            continue;
        }
        int cand = max(0, arr[i] - k + 1);
        for(int j = cand; j <= arr[i]; j++){
            if(hasAssigned[j] == -1){
                for(int m = j; m <= arr[i]; m++){
                    hasAssigned[m] = j;
                }
                break;
            }
            else{
                if(isHead[j]){
                    for(int m = j; m <= arr[i]; m++){
                        hasAssigned[m] = j;
                    }
                    break;
                }
            }
        }
        ans[i] = hasAssigned[arr[i]];
        isHead[ans[i]] = 1;
    }

    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;


    return 0;
}
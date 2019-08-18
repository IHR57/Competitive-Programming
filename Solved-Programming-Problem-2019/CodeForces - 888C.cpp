#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int cs[MAX][26], temp[26];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string str;

    cin>>str;
    
    int n = str.size();

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 26; j++){
            if(str[i-1] - 'a' == j)
                cs[i][j] = cs[i-1][j] + 1;
            else
                cs[i][j] = cs[i-1][j];
        }
    }

    int low = 1, high = n, mid, ans;

    while(low <= high){
        mid = (low + high + 1) >> 1;
        memset(temp, 0, sizeof(temp));
        for(int i = 1; i <= n - mid + 1; i++){
            for(int j = 0; j < 26; j++){
                int t = cs[i+mid-1][j] - cs[i-1][j];
                if(t > 0){
                    temp[j] += 1;
                }
            }
        }
        bool flag = false;
        for(int i = 0; i < 26; i++){
            if(temp[i] == n - mid + 1){
                flag = true;
                break;
            }
        }
        if(flag){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}

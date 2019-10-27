//Date: 03/10/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 1005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

string str;

int cs[2000][26], dp[26][2000], n;
char ch;

void precal()
{
    for(int i = 0; i < 26; i++){
        for(int j = 1; j <= n; j++){
            int low = j, high = n, mid, ans = -1;
            while(low <= high){
                mid = (low + high + 1) >> 1;
                bool flag = false;
                for(int k = 1; k <= n - mid + 1; k++){
                    int toti = cs[k+mid-1][i] - cs[k-1][i];
                    int rem = mid - toti;
                    if(rem <= j){
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    ans = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            dp[i][j] = ans;
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
    int q, k;

    cin>>n;
    cin>>str;

    cin>>q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            cs[i+1][j] = cs[i][j];
        }
        cs[i+1][str[i]-'a'] = cs[i][str[i]-'a'] + 1;
    }

    precal();

    for(int i = 0; i < q; i++){
        cin>>k>>ch;
        cout<<dp[ch-'a'][k]<<endl;
    }
    return 0;
}
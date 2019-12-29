//Date: 30/09/19
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
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

string s;
int n, k;

int numberOfChange(string str)
{
    int Min = 1e8, cnt = 0;
    for(int i = 0; i < n; i++){
        if(i >= k){
            if(str[i-k] != s[(i-k)%3]){
                cnt--;
            }
        }
        if(str[i] != s[i%3])
            cnt++;
        if(i >= k - 1){
            Min = min(Min, cnt);
        }
    }

    return Min;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int test, caseno = 1;
    string str;

    cin>>test;

    while(test--){
        cin>>n>>k;
        cin>>str;
        s = "RGB";
        int ans = numberOfChange(str);
        s = "GBR";
        ans = min(ans, numberOfChange(str));
        s = "BRG";
        ans = min(ans, numberOfChange(str));
        cout<<ans<<endl;
    }

    return 0;
}
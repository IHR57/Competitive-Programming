//Date: 17/10/19
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
#define MAX 100005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

string str, res;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    cin>>str;

    int n = str.length(), k = n - 1, idx = 1;
    bool flag = false;

    if(n == 1){
        res += str;
    }
    res += str;
    for(int i = 1; i < n; i++){
        flag = true;
        int m = n - i;
        for(int j = 0; j < m && flag; j++){
            if(str[i+j] != str[n-j-1]){
                flag = false;
            }
        }
        if(flag){
            for(int j = i - 1; j >= 0; j--){
                res += str[j];
            }
            break;
        }
    }

    cout<<res<<endl;

    return 0;
}
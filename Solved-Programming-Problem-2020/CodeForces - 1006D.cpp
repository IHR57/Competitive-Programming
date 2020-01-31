//Date: 12/01/20
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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    string str1, str2;

    cin>>n;
    cin>>str1>>str2;

    int ans = 0;
    for(int i = 0; i < n / 2; i++){
        char a = str1[i], b = str1[n-i-1], c = str2[i], d = str2[n-i-1];
        map<char, int> mp;
        mp[a]++, mp[b]++, mp[c]++, mp[d]++;
        if(mp.size() == 4)
            ans += 2;
        if(mp.size() == 3){
            if(a == b)
                ans += 1;
            ans += 1;
        }
        if(mp.size() == 2){
            if(mp[a]!= 2)
                ans++;
        }
    }
    if((n & 1) && (str1[n/2] != str2[n/2]))
        ans++;

    cout<<ans<<endl;


    return 0;
}
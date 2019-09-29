//Problem ID: CodeForces - 653B (Bear and Compressing)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 08/09/19
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

int n, vis[6], num[6], cnt;
map<string, string> mp;

bool isPossible()
{
    string str;
    for(int i = 0; i < n; i++){
        str += char(num[i] + 97);
    }
    while(true){
        //cout<<str<<endl;
        if(str.size() == 1 && str[0] == 'a')
            return true;
        string temp = str.substr(0, 2);
        if(!mp.count(temp))
            return false;
        str.erase(0, 2);
        str += mp[temp];
        reverse(str.begin(), str.end());
    }
}

void solve(int pos)
{
    if(pos >= n){
        if(isPossible()){
            cnt++;
        }
        return;
    }
    for(int i = 0; i < 6; i++){
        vis[i] = 1;
        num[pos] = i;
        solve(pos + 1);
        vis[i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int q;
    string a, b;

    cin>>n>>q;

    for(int i = 0; i < q; i++){
        cin>>a>>b;
        mp[a] = b;
    }
    solve(0);
    cout<<cnt<<endl;

    return 0;
}

#include <bits/stdc++.h>
#define MAX 1005
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;

typedef long long ll;

int dp[MAX][MAX];
int freq[30];
string s, t;

int solve(int i, int j)
{
    if(i >= s.size() || j >= t.size())
        return 0;
    if(s[i] >= 'A' && s[i] <= 'Z' && (s[i] != t[j])){
        return 0;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    int ret = 0;
    if(s[i] >= 'A' && s[i] <= 'Z' && s[i] == t[j]){
        ret = 1 + solve(i + 1, j + 1);
    }
    else if(s[i] >= 'a' && s[i] <= 'z' && s[i]-'a' == t[j]-'A'){
        ret = max(1 + solve(i + 1, j + 1), solve(i + 1, j));
    }
    else{
        ret = solve(i + 1, j);
    }
    return dp[i][j] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test;

    cin>>test;

    while(test--){
        cin>>s>>t;
        memset(dp, -1, sizeof(dp));
        int res = solve(0, 0);
        //cout<<res<<endl;
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z')
                temp += s[i];
        }
        if(temp.size() > t.size()){
            cout<<"NO"<<endl;
            continue;
        }
        if(res >= t.size()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}

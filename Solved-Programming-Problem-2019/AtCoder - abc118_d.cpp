#include <bits/stdc++.h>
#define MAX 10005
#define INF 1e9
using namespace std;

typedef long long ll;

string dp[MAX];
int arr[] = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6}, mark[20];

bool isGreater(string& s, string& t)
{
    if(s.size() != t.size())
        return s.size() > t.size();
    return s > t;
}

string solve(int n)
{
    if(n == 0)
        return "";
    if(dp[n] != "")
        return dp[n];
    string ret = "";
    for(int i = 1; i < 10; i++){
        if(mark[i]){
            if(n - arr[i] >= 0){
                char ch = i + 48;
                string temp = ch + solve(n - arr[i]);
                if(temp[temp.size()-1] == '#')
                    continue;
                if(isGreater(temp, ret)){
                    ret = temp;
                }
            }
        }
    }
    if(ret == "")
        ret = "#";
    return dp[n] = ret;
}   

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, m;

    cin>>n>>m;

    int val;
    for(int i = 0; i < m; i++){
        cin>>val;
        mark[val] = 1;
    }

    string res = solve(n);

    cout<<res<<endl;

    return 0;
}
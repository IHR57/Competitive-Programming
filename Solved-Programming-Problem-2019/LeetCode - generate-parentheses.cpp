//Date: 15/10/19
//Tag: Recursion/Backtracking
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
#define MAX 300005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

class Solution {
public:
    int number[100];
    vector<string> vs;
    void solve(int pos, int n, int cnt)
    {
        if(pos >= n && cnt == 0){
            string st = "";
            for(int i = 0; i < n; i++){
                (number[i]) ? st += "(" : st += ")";
            }
            vs.pb(st);
            return;
        }
        else if(pos >= n && cnt != 0)
            return;
        
        number[pos] = 1;
        solve(pos + 1, n, cnt + 1);
        if(cnt - 1 >= 0){
            number[pos] = 0;
            solve(pos + 1, n, cnt - 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        solve(0, 2*n, 0);
        return vs;
    }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution obj = Solution();
    vector<string> res = obj.generateParenthesis(4);
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<endl;
    }

    return 0;
}
/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

stack<pair<char, int> > st;
string str;
int ans[MAX], dp[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int test, caseno = 1;

    cin>>test;

    while(test--){
        cin>>str;
        int len = str.size();
        memset(ans, 0, sizeof(ans));
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < len; i++){
            if(str[i] == '<' || str[i] == '(' || str[i] == '[' || str[i] == '{'){
                st.push(mp(str[i], i));
            }
            else{
                if(st.empty())
                    continue;
                if((st.top().ff == '(' && str[i] == ')') || (st.top().ff == '<' && str[i] == '>') || (st.top().ff == '[' && str[i] == ']') || (st.top().ff == '{' && str[i] == '}')){
                    ans[st.top().ss] = i - st.top().ss + 1;
                    st.pop();
                }
                else{
                    while(!st.empty()){
                        st.pop();
                    }
                }
            }   
        }
        cout<<"Case "<<caseno++<<":"<<endl;
        int n = len;
        for(int i = n - 1; i >= 0; i--){
            if(ans[i] > 0 && i + ans[i] <= n - 1 && ans[i + ans[i]] > 0){
                dp[i] = ans[i] + dp[i + ans[i]];
            }
            else{
                dp[i] = ans[i];
            }
        }
        for(int i = 0; i < n; i++){
            cout<<dp[i]<<endl;
        }
        while(!st.empty())
            st.pop();
    }
    return 0;
}

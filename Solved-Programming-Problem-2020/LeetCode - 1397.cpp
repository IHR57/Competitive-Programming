typedef long long ll;
#define MOD 1000000007


class Solution {
public:
    
    ll dp[505][2][105];
    int lim;
    string st;
    vector<int> p;
    vector<int> digit;
    
    vector<int> kmp(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    
    ll solve(int pos, int isSmall, int cnt)
    {
        if(pos >= lim){
            if(cnt < st.size())
                return 1;
            return 0;
        }
        if(dp[pos][isSmall][cnt] != -1)
            return dp[pos][isSmall][cnt];
        
        int last = isSmall ? 25 : digit[pos];
        ll ret = 0;
        
        for(int i = 0; i <= last; i++){
            if(i == (st[cnt] -'a')){
                if(cnt + 1 < st.size()){
                    ret = (ret + solve(pos + 1, isSmall | (i < digit[pos]), cnt + 1)) % MOD;
                }
            }
            else{
                int temp = 0;
                if(cnt > 0){
                    int j = p[cnt-1];
                    while(j > 0 && st[j] - 'a' != i){
                        j = p[j-1];
                    }
                    if(st[j]-'a' == i)
                        j++;
                    temp = j;
                }
                else{
                    temp = (i == st[0]-'a');
                }
                ret = (ret + solve(pos + 1, isSmall | (i < digit[pos]), temp)) % MOD;
            }
        }
        
        return dp[pos][isSmall][cnt] = ret % MOD;
    }
    
    ll cal(string x)
    {
        digit.clear();
        for(int i = 0; i < x.size(); i++)
            digit.push_back(x[i] - 'a');

        lim = digit.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0) % MOD;
    }
    
    int findGoodStrings(int n, string s1, string s2, string evil) {
        st = evil;
        size_t found = s1.find(st);
        int ans = 0;
        if (found==std::string::npos){
            ans = 1;
        }
        
        p = kmp(st);
        
        int res = cal(s2) - cal(s1);
        if(res < 0)
            res += MOD;
        
        return (res + ans) % MOD;
    }
};
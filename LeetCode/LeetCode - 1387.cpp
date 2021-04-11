class Solution {
int dp[1000005];
    
public:
    int solve(int n)
    {
        if(n == 1){
            return 0;
        }
        if(dp[n] != -1)
            return dp[n];
        int ret = 0;
        if(n & 1)
            ret = 1 + solve(3 * n + 1);
        else
            ret =  1 + solve(n / 2);
        return dp[n] = ret;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int> > v;
        memset(dp, -1, sizeof(dp));
        for(int i = lo; i <= hi; i++){
            v.push_back(make_pair(solve(i), i));
        }
        
        sort(v.begin(), v.end());
    
        return v[k-1].second;
    }
};
class Solution {
public:
    int dp[505][505], vis[505][505];
    int n;
    int solve(vector<int>& satisfaction, int pos, int cnt)
    {
        if(pos >= n)
            return 0;
        if(vis[pos][cnt] != 0)
            return dp[pos][cnt];
        int ret = 0;
        vis[pos][cnt] = 1;
        ret = max(solve(satisfaction, pos + 1, cnt), (cnt + 1) * satisfaction[pos] + solve(satisfaction, pos + 1, cnt + 1));
        
        return dp[pos][cnt] = ret;
        
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(), satisfaction.end());
        n = satisfaction.size();
        memset(vis, 0, sizeof(vis));
        
        int res = solve(satisfaction, 0, 0);
        
        return res;
    }
};

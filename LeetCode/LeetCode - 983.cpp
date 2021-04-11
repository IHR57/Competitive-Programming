class Solution {
int dp[400];
int n;
int nd[3] = {1, 7, 30};
    
public:
    int solve(int pos, vector<int>&days, vector<int>& costs){
        if(pos >= n)
            return 0;
        if(dp[pos] != -1)
            return dp[pos];
        int ret = 1<<28;
        
        for(int i = 0; i < 3; i++){
            int idx = lower_bound(days.begin(), days.end(), days[pos] + nd[i]) - days.begin();
            ret = min(ret, costs[i] + solve(idx, days, costs));
        }
        
        return dp[pos] = ret;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));   
        n = (int) days.size();
        int res = solve(0, days, costs);
        return res;
    }
};
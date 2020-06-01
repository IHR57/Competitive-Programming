class Solution {
public:
    int dp[75][75][75], n, m;
    int dir[3] = {-1, 0, 1};
    int solve(int k, int i, int j, vector<vector<int>>& grid) {
        if(k >= n) {
            return 0;
        }
        if(dp[k][i][j] != -1) {
            return dp[k][i][j];
        }
        
        int ret2 = 0;
        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++){
                int tx = i + dir[x], ty = j + dir[y];
                if(tx >= 0 && tx < m && ty >= 0 && ty < m)
                    ret2 = max(ret2, grid[k][i] + ((i != j) ? grid[k][j] : 0) + solve(k + 1, tx, ty, grid));
            }
        }
        
        return dp[k][i][j] =  ret2;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int res = solve(0, 0, m - 1, grid);
        cout<<res<<endl;
        
        return res;
    }
};
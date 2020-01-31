class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = (int) A[0].size();
        int dp[n+1][n+1];
        
        for(int i = 0; i < n; i++)
            dp[0][i] = A[0][i];
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = 1<<28;
                if(i-1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + A[i][j]);
                if(j - 1 >= 0){
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + A[i][j]);
                }
                if(j + 1 < n){
                    dp[i][j] = min(dp[i][j], dp[i-1][j+1] + A[i][j]);
                }
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        
        int Mn = 1<<28;
        for(int i = 0; i < n; i++){
            Mn = min(Mn, dp[n-1][i]);
        }
        
        return Mn;
    }
};
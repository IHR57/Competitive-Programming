class Solution {
public:
    int n, m;
    double total = 0, cnt = 0;
    int dp[10][10];
    void solve(int pos, int a, int b, int sum, double p, vector<int>& balls) {
        if(pos >= n) {
            if(sum == m) {
                cnt += (a == b) * p;
                total += p;
            }
            return;
        }
        for(int i = 0; i <= balls[pos] && i + sum <= m; i++) {
            int tempA = a + (i > 0);
            int tempB = b + (balls[pos] - i > 0);
            solve(pos + 1, tempA, tempB, i + sum, p * dp[balls[pos]][i], balls);
        }
    }
    
    double getProbability(vector<int>& balls) {
        dp[0][0] = 1;
        for(int i = 1; i < 10; i++) {
            dp[i][0] = dp[i][i] = 1;
            for(int j = 1; j < i; j++){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
        n = balls.size();
        for(int i = 0; i < n; i++) 
            m += balls[i];
        
        m >>= 1;
        
        solve(0, 0, 0, 0, 1, balls);
        
        return cnt / total;
        
    }
};
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> maxRow(n + 1, 0), maxCol(n + 1, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                maxRow[i] = max(maxRow[i], grid[i][j]);
                maxCol[j] = max(maxCol[j], grid[i][j]);
            }
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += min(maxCol[j], maxRow[i]) - grid[i][j];
            }
        }
        
        return sum;
    }
};
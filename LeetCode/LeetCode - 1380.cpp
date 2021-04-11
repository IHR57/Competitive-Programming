#define pb push_back

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int rowMin[n+1], colMax[m+1] = {0};
        for(int i = 0; i < n; i++)
            rowMin[i] = 1<<28;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rowMin[i] = min(rowMin[i], matrix[i][j]);
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }
        
        vector<int> res;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]){
                    res.pb(matrix[i][j]);
                }
            }
        }
        
        return res;
    }
};
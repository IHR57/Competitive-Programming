class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int Max = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                Max = max(Max, (nums[i]- 1) * (nums[j]-1));
            }
        }
        
        return Max;
    }
};
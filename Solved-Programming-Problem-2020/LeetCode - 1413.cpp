class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size(), ans;
        for(int i = 1; ; i++){
            bool flag = false;
            int sum = i;
            for(int j = 0; j < n; j++){
                sum += nums[j];
                if(sum < 1){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};
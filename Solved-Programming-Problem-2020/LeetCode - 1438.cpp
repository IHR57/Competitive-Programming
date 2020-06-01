class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0, j = 0;
        multiset<int> ms;
        
        ms.insert(nums[0]);
        int res = 1;
        for(i = 1; i < n; i++){
            ms.insert(nums[i]);
            while((*ms.rbegin() - *ms.begin()) > limit) {
                ms.erase(ms.find(nums[j]));
                j++;
            }
            res = max(res, i - j + 1);
        }
        
        return res;
    }
};
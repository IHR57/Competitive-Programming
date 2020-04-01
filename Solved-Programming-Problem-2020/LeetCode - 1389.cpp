class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int target[505];
        int n = nums.size();
        for(int i = 0; i < 3 * n; i++)
            target[i] = -1;
        
        for(int i = 0; i < n; i++){
            if(target[index[i]] == -1)
                target[index[i]] = nums[i];
            else{
                int arr[105], k = 0;
                for(int j = index[i]; target[j] != -1; j++){
                    arr[k++] = target[j];
                }
                target[index[i]] = nums[i];
                for(int j = index[i] + 1, x = 0; x < k; j++, x++)
                    target[j] = arr[x];
            }
        }
        vector<int> res;
        for(int i = 0; i < 3 * n; i++){
            if(target[i] == -1)
                break;
            res.push_back(target[i]);
        }
        
        return res;
    }
};
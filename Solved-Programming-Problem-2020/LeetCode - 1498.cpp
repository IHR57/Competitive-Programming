#define MAX 100005
#define MOD 1000000007
int pow2[MAX];

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        pow2[0] = 1;
        for(int i = 1; i < MAX; i++) {
            pow2[i] = (pow2[i-1] * 2) % MOD;
        }
        
        int j = n - 1, ans = 0;
        for(int i = 0; i < n; i++) {
            while(i <= j && nums[i] + nums[j] > target) {
                j--;
            }
            if(i > j)
                break;
            ans += pow2[j-i];
            ans %= MOD;
        }
        
        return ans;
    }
};
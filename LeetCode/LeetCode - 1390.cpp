class Solution {
public:
    pair<int, int> countDivisor(int n)
    {
        int sum = 0;
        int cnt = 0;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                cnt++;
                sum += i;
                if(n / i != i){
                    cnt++;
                    sum += n / i;
                }
            }
        }
        
        return make_pair(sum, cnt);
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            pair<int, int> x = countDivisor(nums[i]);
            if(x.second == 4){
                ans +=  x.first;
            }
        }
        
        return ans;
    }
};
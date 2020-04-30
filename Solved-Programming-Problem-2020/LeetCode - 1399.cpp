class Solution {
public:
    int sod(int x)
    {
        int sum = 0;
        while(x){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    
    int countLargestGroup(int n) {
        vector<int> cnt(50, 0);
        int Max = 0;
        for(int i = 1; i <= n; i++){
            cnt[sod(i)]++;
            Max = max(Max, cnt[sod(i)]);
        }
        
        int ans = 0;
        for(int i = 0; i < 50; i++){
            if(cnt[i] == Max)
                ans++;
        }
        
        return ans;
        
    }
};

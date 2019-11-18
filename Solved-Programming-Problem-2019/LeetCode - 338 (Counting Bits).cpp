#define pb push_back

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.pb(0);
        int temp = 0;
        if(num >= 1)
            ans.pb(1);
        if(num >= 2)
            ans.pb(1);
        if(num >= 3)
            ans.pb(2);
        for(int i = 4; i <= num; i++){
            if((i & (i - 1)) == 0){
                temp++;
            }
            if(i  >= (1 << (temp + 1)) + (1 << temp))
                ans.pb(ans[i-(1<<temp)] + 1);
            else
                ans.pb(ans[i-(1<<temp)]);
        }
        
        return ans;
    }
};
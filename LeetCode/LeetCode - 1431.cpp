class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int Max = 0;
        for(int i = 0; i < candies.size(); i++)
            Max = max(Max, candies[i]);
        
        vector<bool> v;
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= Max){
                v.push_back(true);
            }
            else
                v.push_back(false);
        }
        
        return v;
    }
};
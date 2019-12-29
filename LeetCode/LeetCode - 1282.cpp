#define pb push_back

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<int> result[n + 1];
        for(int i = 0; i < groupSizes.size(); i++){
            result[groupSizes[i]].pb(i);
        }
        
        vector<vector<int> > ans;
        for(int i = 1; i <= n; i++){
            vector<int> temp;
            if(!result[i].empty()){
                for(int j = 0; j < result[i].size(); j++){
                    if(j % i == 0){
                        if(!temp.empty()){
                            ans.pb(temp);
                        }
                        temp.clear();
                        temp.pb(result[i][j]);
                    }
                    else{
                        temp.pb(result[i][j]);
                    }
                }
                ans.pb(temp);
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        map<string, int> mp;
        int n = favoriteCompanies.size();
        vector<int> v[n + 1];
        
        int idx = 1;
        for(int i = 0; i < n; i++) {
            sort(favoriteCompanies[i].begin(), favoriteCompanies[i].end());
        }
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            bool flag = false;
            int cnt = 0;
            for(int j = 0;  j < n; j++) {
                if(i == j)
                    continue;
                int ptr = 0;
                for(int k = 0; k < favoriteCompanies[j].size(); k++) {
                    if(ptr < favoriteCompanies[i].size() && favoriteCompanies[i][ptr] == favoriteCompanies[j][k]) {
                        ptr++;
                    }
                }
                if(ptr == favoriteCompanies[i].size()) {
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
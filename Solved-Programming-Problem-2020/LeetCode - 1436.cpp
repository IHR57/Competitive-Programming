class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<pair<string, int> > s;
        int n = paths.size();
        
        string ans;
        for(int i = 0; i < n; i++){
            if(s.count(make_pair(paths[i][0], -1))){
                s.erase(make_pair(paths[i][0], -1));
            }
            else
                s.insert(make_pair(paths[i][0], 1));
            if(s.count(make_pair(paths[i][1], 1))){
                s.erase(make_pair(paths[i][1], 1));
            }
            else{
                ans = paths[i][1];
                s.insert(make_pair(paths[i][1], -1));
            }
            
        }
        for(set<pair<string, int> > :: iterator it = s.begin(); it != s.end(); it++){
            if(it->second == -1)
                ans = it->first;
        }
        
        return ans;
    }
};
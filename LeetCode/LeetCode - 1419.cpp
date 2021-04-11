class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.size();
        set<int> s[5];
        vector<int> cs(n + 1, 0);
        for(int i = 0; i < n; i++){
            if(croakOfFrogs[i] == 'c')
                s[0].insert(i);
            else if(croakOfFrogs[i] == 'r')
                s[1].insert(i);
            else if(croakOfFrogs[i] == 'o')
                s[2].insert(i);
            else if(croakOfFrogs[i] == 'a')
                s[3].insert(i);
            else if(croakOfFrogs[i] == 'k')
                s[4].insert(i);
            else
                return -1;
            cs[i+1] = cs[i] + (croakOfFrogs[i] == 'c');
        }
        
        
        int cnt = 0;
        vector<int> v;
        int prev = 2e9;
        for(set<int> :: iterator it = s[0].begin(); it != s[0].end(); it++) {
            int start = *it;
            prev = *it;
            v.push_back(*it);
            for(int j = 1; j < 5; j++){
                if(s[j].empty())
                    return -1;
                set<int> :: iterator it1 = s[j].lower_bound(prev);
                if(it1 == s[j].end())
                    return -1;
                prev = *it1;
                v.push_back(*it1);
                s[j].erase(*it1);
            }
            cnt = max(cnt, cs[prev+1] - cs[start]);
        }
        
        return cnt;
        
    }
};
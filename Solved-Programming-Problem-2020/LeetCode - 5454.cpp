class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> mp, mp1;
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }
        
        vector<pair<int, int> > vp;
        
        int idx = 1;
        for(int i = 0; i < arr.size(); i++) {
            if(mp1[arr[i]] == 0) {
                vp.push_back(make_pair(mp[arr[i]], arr[i]));
                mp1[arr[i]] = idx++;
            }
        }
        
        sort(vp.begin(), vp.end());
        
        int cnt = 0;
        for(int i = 0; i < vp.size(); i++) {
            if(k == 0) {
                cnt++;
            }
            else if(vp[i].first <= k) {
                k -= vp[i].first;
            }
            else {
                k -= min(k, vp[i].first);
                cnt++;
            }
        }
        
        return cnt;
    }
};
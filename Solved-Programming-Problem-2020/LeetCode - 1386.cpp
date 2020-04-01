class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, int> mp;
        int m = reservedSeats.size();
        int idx = 1;
        vector<int> v[100005];
        for(int i = 0; i < m; i++){
            if(mp[reservedSeats[i][0]] == 0){
                mp[reservedSeats[i][0]] = idx++;
            }
            v[mp[reservedSeats[i][0]]].push_back(reservedSeats[i][1]);
        }
        
        long long cnt = 1;
        for(int i = 1; i < idx; i++){
            int vis[11] = {0};
            for(int j = 0; j < v[i].size(); j++){
                vis[v[i][j]] = 1;
            }
            if(!vis[2] && !vis[3] && !vis[4] && !vis[5] && !vis[6] && !vis[7] && !vis[8] && !vis[9])
                cnt += 2;
            else if(!vis[4] && !vis[5] && !vis[6] && !vis[7])
                cnt += 1;
            else if((!vis[2] && !vis[3] && !vis[4] && !vis[5]) || (!vis[6] && !vis[7] && !vis[8] && !vis[9]))
                cnt += 1;
        }
        
        idx -= 1;
        int rem = n - idx;
        cnt += (1LL * rem * 2);
        
        return cnt - 1;
    }
};
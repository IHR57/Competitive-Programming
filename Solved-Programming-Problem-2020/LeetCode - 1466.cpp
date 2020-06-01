class Solution {
public:
    vector<pair<int, int> >graph[50005];
    int cnt = 0;
    
    void dfs(int u, int par) {
        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            if(v ==  par)
                continue;
            if(graph[u][i].second == 0)
                cnt++;
            dfs(v, u);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        for(int i = 0; i < n - 1; i++){
            int u = connections[i][0], v = connections[i][1];
            graph[u].push_back(make_pair(v, 0));
            graph[v].push_back(make_pair(u, 1));
        }
        dfs(0, -1);
        
        return cnt;
    }
};
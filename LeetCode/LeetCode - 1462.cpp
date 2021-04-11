class Solution {
public:
    vector<int> graph[105];
    set<int> s[105];
    int vis[105];
    
    void dfs(int u, int root) {
        s[root].insert(u);
        vis[u] = 1;
        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if(!vis[v]) {
                dfs(v, root);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int m = prerequisites.size();
        for(int i = 0; i < m; i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i = 0; i < n; i++) {
            memset(vis, 0, sizeof(vis));
            dfs(i, i);
        }
        
        int k = queries.size();
        vector<bool> vb;
        
        for(int i = 0; i < k; i++) {
            if(s[queries[i][0]].count(queries[i][1]))
                vb.push_back(true);
            else
                vb.push_back(false);
        }
        
        return vb;
    }
};
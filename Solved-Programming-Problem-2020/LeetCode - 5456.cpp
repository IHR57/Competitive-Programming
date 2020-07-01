#define MAX 50005

class TreeAncestor {
public:
    
    vector<int> tree[MAX];
    int depth[MAX], T[MAX];
    int parent[MAX][17];

    void dfs(int from, int u, int dep)
    {
        T[u] = from;
        depth[u] = dep;

        for(int i = 0; i < tree[u].size(); i++){
            int v = tree[u][i];
            if(v == from)
                continue;
            dfs(u, v, dep + 1);
        }
    }

    void LCAinit(int n)
    {
        memset(parent, -1, sizeof(parent));

        for(int i = 0; i < n; i++){
            parent[i][0] = T[i];
        }

        for(int j = 1; (1<<j) < n; j++){
            for(int i = 0; i < n; i++){
                if(parent[i][j-1] != -1){
                    parent[i][j] = parent[parent[i][j-1]][j-1];
                }
            }
        }
    }

    int LCAquery(int p, int k)
    {

        int lg = 1;
        while(1){
            int next = lg + 1;
            if((1<<next) > depth[p]){
                break;
            }
            lg++;
        }
        
        int x = depth[p] - k;
        if(x < 0)
            return -1;
        if(x == 0)
            return 0;
        
        for(int i = lg; i >= 0; i--){
            if(depth[p] - (1<<i) >= x){
                p = parent[p][i];
            }
        }

        return p;
    }

    TreeAncestor(int n, vector<int>& parent) {
        for(int i = 1; i < n; i++) {
            tree[i].push_back(parent[i]);
            tree[parent[i]].push_back(i);
        }
        dfs(0, 0, 0);
        LCAinit(n);
    }
    
    int getKthAncestor(int node, int k) {
        
        return LCAquery(node, k);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
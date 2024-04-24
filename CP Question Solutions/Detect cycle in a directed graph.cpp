class Solution { 
  public:
    vector<int> global_vis;
    bool dfs(int i, vector<int>* adj, vector<int>& vis){
        if(global_vis[i] == 1) {
            // cout<< i;
            return false;
        }
        if(vis[i] != 0) return true;
        vis[i] = 1;
        for(int j : adj[i]){
            if(dfs(j, adj, vis)) return true;
        }
        
        vis[i] = 0;
        global_vis[i] = 1;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        global_vis.resize(n, 0);
        for(int i = 0; i < n; i++){
            if(global_vis[i] == 1) continue;
            vector<int> vis(n, 0);
            if(dfs(i, adj, vis)) return true;
            global_vis[i] = 1;
        }
        return false;
    }
};

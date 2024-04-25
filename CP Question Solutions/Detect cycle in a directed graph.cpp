class Solution {
  private:
    vector<bool> path;
    vector<int> vis;
  public:
    bool dfs(int v, vector<int>* adj){
        if(vis[v] == 1) return true;
        if(path[v] == false) return false;
        int n = adj[v].size();
        vis[v] = 1;
        for(int i = 0; i < n; i++){
            if(dfs(adj[v][i], adj)) return true;
        }
        path[v] = false;
        vis[v] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        path.resize(n, true);
        vis.resize(n, 0);
        for(int i = 0; i < n; i++){
            if(path[i] == false) continue;
            if(dfs(i, adj)) return true;
            path[i] = false;
        }
        return false;
    }
};

class Solution {
  private:
    vector<int> vis;
  public:
    void dfs(int vertex, vector<vector<int>>& adj, int n){
        if(vis[vertex] == 1) return;
        vis[vertex] = 1;
        for(int i = 0; i < n; i++){
            if(adj[vertex][i] == 1){
                dfs(i, adj, n);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        vis.resize(V,0);
        int res = 0;
        for(int i = 0; i < V; i++){
            if(vis[i] == 0) {
                dfs(i, adj, V);
                res++;
            }
        }
        return res;
    }
};

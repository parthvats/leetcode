class Solution {
  private:
    vector<int> vis;
    vector<int> res;
    
  public:
    void dfs(int vertex, vector<int> adj[]){
        if(vis[vertex] == 1) return;
        res.push_back(vertex);
        vis[vertex] = 1;
        for(auto it: adj[vertex]){
            dfs(it, adj);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vis.resize(V, 0);
        dfs(0, adj);
        return res;
    }
};

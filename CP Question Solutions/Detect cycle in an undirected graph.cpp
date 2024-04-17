class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
    
        int ver;
        int sz;
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++){
            if(vis[i] == 1) continue;
            q.push(i);
            
            while(!q.empty()){
                ver = q.front();
                sz = adj[ver].size();
                q.pop();
                if(vis[ver] == 1) return 1;
                vis[ver] = 1;
                
                for(int i = 0; i < sz; i++){
                    if(vis[adj[ver][i]] == 0){
                        q.push(adj[ver][i]);
                    }  
                }
                
            }
        }
        
        
        
        return 0;
    }
};

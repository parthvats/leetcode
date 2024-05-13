class Solution {
  private:
    vector<int> vis;
    stack<int> s;
  public:
    void toposort(int v, vector<vector<pair<int, int>>>& adj){
        if(vis[v] == 1) return;
        int n = adj[v].size();
        vis[v] = 1;
        
        for(int i = 0; i < n; i++){
            toposort(adj[v][i].first, adj);
        }
        
        s.push(v);
    }
    
     vector<int> shortestPath(int n,int m, vector<vector<int>>& e){
        vector<vector<pair<int, int>>> adj(n);
        
        for(int i = 0; i < m; i++){
            adj[e[i][0]].push_back({e[i][1], e[i][2]});
        }
        
        vis.resize(n, 0);
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 1) continue;
            toposort(i, adj);
        }
        
        vector<int> dis(n, INT_MAX);
        dis[0] = 0;
        
        while(s.top() != 0){
            if(dis[s.top()] == INT_MAX){
                dis[s.top()] = -1;
                s.pop();
            }
        }
        
        
        while(!s.empty()){
            int ver = s.top();
            int sz = adj[ver].size();
            int d = dis[ver];
            
            for(int i = 0; i < sz; i++){
                dis[adj[ver][i].first] = min(d+adj[ver][i].second, dis[adj[ver][i].first]);
            }
            s.pop();
        }
        
        return dis;
        
    }
};

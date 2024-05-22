class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& e, int n,int m, int src){
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < m; i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        
        vector<int> vis(n, 0);
        vector<int> dis(n, -1);
        dis[src] = 0;
        vis[src] = 1;
        
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int sz = adj[node.first].size();
            for(int i = 0; i < sz; i++){
                if(vis[adj[node.first][i]] == 1) continue; 
                q.push({adj[node.first][i], node.second+1});
                dis[adj[node.first][i]] = node.second+1;
                vis[adj[node.first][i]] = 1;
            }
        }
        
        return dis;
    }
};


// Better SOlution
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& e, int n,int m, int src){
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < m; i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        
        vector<int> vis(n, 0);
        vector<int> dis(n, -1);
        dis[src] = 0;
        vis[src] = 1;
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int sz = adj[node].size();
            for(int i = 0; i < sz; i++){
                if(vis[adj[node][i]] == 1) continue; 
                q.push(adj[node][i]);
                dis[adj[node][i]] = dis[node]+1;
                vis[adj[node][i]] = 1;
            }
        }
        
        return dis;
    }
};

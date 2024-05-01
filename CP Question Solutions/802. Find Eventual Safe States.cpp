class Solution {
private:
    vector<int> vis;
    vector<bool> path;
    vector<int> res;
    bool b = false;
public:
    void dfs(int v, vector<vector<int>>& adj){
        if(vis[v] == 1){
            b = true;
            return;
        }
        if(path[v] == true) return;
        int sz = adj[v].size();
        vis[v] = 1;
        for(int i = 0; i < sz; i++){
            dfs(adj[v][i], adj);
            if(b) return;
        }
        vis[v] = 0;
        path[v] = true;
        res.push_back(v);
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        path.resize(n, false);
        vis.resize(n,0);

        for(int i = 0; i < n; i++){
            if(path[i] == true){
                cout<< i << endl;
                continue;
            } 
            dfs(i, adj);
            b = false;
        }
        sort(res.begin(), res.end());
        return res;
    }
};


// BFS outdegree (khan's algo)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> adj_inv(n);
        vector<int> out_deg(n, 0);
        queue<int> q;
        
        for(int i = 0; i < n; i++){
            int sz = adj[i].size();
            for(int j = 0; j < sz; j++){
                adj_inv[adj[i][j]].push_back(i);
            }
            out_deg[i] = sz;
            if(sz == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj_inv[node]){
                out_deg[it]--;
                if(out_deg[it] == 0) q.push(it);
            }
        }
        
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(out_deg[i] == 0) res.push_back(i);
        }
        
        return res;
    }
};


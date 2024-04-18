class Solution {
private:
    vector<vector<int>> adj;
    vector<int> vis;
    int right;
    int left;
public:
    bool dfs(int x){
        if(x == right) return true;
        int sz = adj[x].size();
        vis[x] = 1;
        for(int i = 0; i < sz; i++){
            if(vis[adj[x][i]] == 1 || (x == left && adj[x][i] == right)) {
                continue;
            }
            if(dfs(adj[x][i])) return true;
        }
        return false;
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m = edges.size();
        adj.resize(m+1);

        for(int i = 0; i < m; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i = m-1; i >= 0; i--){
            left = edges[i][0];
            right = edges[i][1];
            vis = vector<int>(m+1);
            if(dfs(edges[i][0])) return edges[i];
            
        }
        return {};
    }
};



// same solution logic as above but here adj matrix is vector<set<int>> instead of vector<vector<int>>
class Solution {
private:
    vector<set<int>> adj;
    vector<int> vis;
    int right;
public:
    bool dfs(int x){
        if(x == right) return true;
        vis[x] = 1;
        for(int i : adj[x]){
            if(vis[i] == 1) continue;
            if(dfs(i)) return true;
        }
        return false;
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m = edges.size();
        adj.resize(m+1);

        for(int i = 0; i < m; i++){
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }

        for(int i = m-1; i >= 0; i--){
            right = edges[i][1];
            adj[edges[i][0]].erase(right);
            vis = vector<int>(m+1);
            if(dfs(edges[i][0])) return edges[i];
            adj[edges[i][0]].insert(right);
            
        }
        return {};
    }
};

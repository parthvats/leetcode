// this solution is based on Course Schedule question but the solution below is much faster and not exaclty based on Course Schedule 
class Solution {
private:
    vector<int> vis;
    vector<bool> path;
    vector<int> res;
public:
    bool dfs(int v, vector<vector<int>>& adj){
        if(vis[v] == 1) return false;
        if(path[v] == true) return true;
        int sz = adj[v].size();
        vis[v] = 1;
        for(int i = 0; i < sz; i++){
            if(!dfs(adj[v][i], adj)) return false;
        }
        path[v] = true;
        vis[v] = 0;
        res.push_back(v);
        return true;
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        int sz = pre.size();

        for(int i = 0; i < sz; i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }

        vis.resize(n, 0);
        path.resize(n, false);

        for(int i = 0; i < n; i++){
            if(path[i] == true) continue;
            if(!dfs(i, adj)) return {}; 
        }

        return res;
    }
};

// better solution
class Solution {
private:
    vector<int> vis;
    vector<bool> path;
    vector<int> res;
    bool b = false;
public:
    void dfs(int v, vector<vector<int>>& adj){
        if(vis[v] == 1) {
            b= true;
            return;
        }
        if(path[v] == true) return;
        int sz = adj[v].size();
        vis[v] = 1;
        for(int i = 0; i < sz; i++){
            dfs(adj[v][i], adj);
            if(b) return;
        }
        path[v] = true;
        vis[v] = 0;
        res.push_back(v);
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        int sz = pre.size();

        for(int i = 0; i < sz; i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }

        vis.resize(n, 0);
        path.resize(n, false);

        for(int i = 0; i < n; i++){
            if(path[i] == true) continue;
            dfs(i, adj);
            if(b) return{};
        }

        return res;
    }
};

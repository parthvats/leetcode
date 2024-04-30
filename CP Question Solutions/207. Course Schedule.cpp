class Solution {
private:
    vector<int> vis;
    vector<bool> path;
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
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        int sz = pre.size();

        for(int i = 0; i < sz; i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }

        vis.resize(n, 0);
        path.resize(n, false);

        for(int i = 0; i < n; i++){
            if(path[i] == true) continue;
            if(!dfs(i, adj)) return false; 
        }

        return true;
    }
};

// by BFS (Khan's Algo)

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
	    
	    for(auto it : pre){
	        adj[it[0]].push_back(it[1]);
	    }
	    
	    vector<int> indeg(n, 0);
	    
	    for(auto it : adj){
	        for(auto i : it){
	            indeg[i]++;
	        }
	    }
	    
	    queue<int> q;
	    int count = 0;
	    
	    for(int i = 0; i < n; i++){
	        if(indeg[i] == 0) {
	            q.push(i);
	            count++;
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        for(auto it : adj[node]){
	            indeg[it]--;
	            if(indeg[it] == 0){
	                q.push(it);
	                count++;
	            }
	        }
	    }

	    return count == n ? true : false;
    }
};

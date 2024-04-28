class Solution
{
    private:
    stack<int> s;
    vector<int> vis;
	public:
	void dfs(int v, vector<int>* adj){
	    if(vis[v] == 1) return;
	    vis[v] = 1;
	    int sz = adj[v].size();
	    for(int i = 0; i < sz; i++){
	        dfs(adj[v][i], adj);
	    }
	    s.push(v);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    vis.resize(n, 0);
	    vector<int> res;
	    
	    for(int i = 0; i < n; i++){
	        dfs(i, adj);
	    }
	    
	    while(!s.empty()){
	        res.push_back(s.top());
	        s.pop();
	    }
	    
	    return res;
	}
};

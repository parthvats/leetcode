class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    vector<int> indeg(n,0);
	    for(int i = 0; i < n; i++){
	        for(auto it : adj[i]){
	            indeg[it]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    
	    for(int i = 0; i < n; i++){
	        if(indeg[i] == 0) q.push(i);
	    }
	    
	    vector<int> res;
	    
	    while(!q.empty()){
	        int temp = q.front();
	        q.pop();
	        res.push_back(temp);
	        
	        for(auto it : adj[temp]){
	            indeg[it]--;
	            if(indeg[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    
	    return res;
	}
};

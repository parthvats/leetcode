class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int> indeg(n, 0);
        
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        
        for(auto it : indeg) {
            if(it != 0) return true;
        }
        
        return false;
    }
};


// BEtter version using a count variable 

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int> indeg(n, 0);
        
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                indeg[it]++;
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
                if(indeg[it] == 0) {
                    q.push(it);
                    count++;
                }
            }
        }
        
        return count == n? false:true;
    }
};

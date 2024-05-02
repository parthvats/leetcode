class Solution{
    private:
        map<char, set<char>> mp;
        stack<int> s;
        vector<int> path;
    public:
    
    void comp(string s1, string s2, vector<vector<int>>& adj){
        int i = 0;
        int sz1 = s1.size();
        int sz2 = s2.size();
        
        while(i < sz1 && i < sz2){
            if(s1[i] == s2[i]) i++;
            else {
                adj[s1[i]-97].push_back(s2[i]-97);
                return;
            }
        }
    }
    
    void dfs(int v, vector<vector<int>>& adj){
        if(path[v] == 1) return;
        int sz = adj[v].size();
        
        for(int i = 0; i < sz; i++){
            dfs(adj[v][i], adj);
        }
        
        path[v] = 1;
        s.push(v);
    }
    
    
    string findOrder(string dict[], int n, int k) {
        
        vector<vector<int>> adj(k);
        
        for(int i = 0; i < n-1; i++){
            comp(dict[i], dict[i+1], adj);
        }
        
        path.resize(k, 0);
        
        for(int i = 0; i < k; i++){
            if(path[i] == 1) continue;
            dfs(i, adj);
        }
        
        string res;
        
        while(!s.empty()){
            res.push_back(static_cast<char>(s.top()+97));
            s.pop();
        }
        
        return res;
    }
};

// by khan's algo

class Solution{
    public:
    
    void comp(string s1, string s2, vector<vector<int>>& adj){
        int i = 0;
        int sz1 = s1.size();
        int sz2 = s2.size();
        
        while(i < sz1 && i < sz2){
            if(s1[i] == s2[i]) i++;
            else {
                adj[s1[i]-97].push_back(s2[i]-97);
                return;
            }
        }
    }
    
    string findOrder(string dict[], int n, int k) {
        
        vector<vector<int>> adj(k);
        
        for(int i = 0; i < n-1; i++){
            comp(dict[i], dict[i+1], adj);
        }
        
        vector<int> indeg(k, 0);
        
        for(int i = 0; i < k; i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < k; i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        string res;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(static_cast<char>(node+97));
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        
        return res;
    }
};

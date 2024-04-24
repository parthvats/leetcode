class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> v(n, 0);
        queue<int> q;

        for(int i = 0; i < ; i++){
            if(v[i] != 0) continue;
            q.push(i);
            int last = 1;
            v[i] = last;

            while(!q.empty()){
                int a = q.front();
                q.pop();
                last = v[a] == 1? 2:1;
                int sz = adj[a].size();

                for(int i = 0; i < sz; i++){
                    int idx = adj[a][i];
                    if(v[idx] != 0){
                        int temp = last == 1?2:1;
                        if(v[idx] == temp) return false;
                    }
                    else{
                        v[idx] = last;
                        q.push(adj[a][i]);
                    }
                    
                }
            }
        }

        
        return true;
    }
};

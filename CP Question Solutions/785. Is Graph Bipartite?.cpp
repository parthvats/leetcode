class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();

        queue<int> q;
        vector<int> v(n, -1);

        for(int i = 0; i < n; i++){
            if(v[i] != -1) continue;
            q.push(i);
            v[i] = 1;
            
            while(!q.empty()){
                int ver = q.front();
                q.pop();
                int curr = v[ver] == 1?0:1;
                int sz = adj[ver].size();

                for(int i = 0; i < sz; i++){
                    int num = adj[ver][i];
                    if(v[num] != -1){
                        if(v[num] == v[ver]) return false;
                    }
                    else{
                        v[num] = curr;
                        q.push(num);
                    }
                } 
            }
        }
        return true;

    }
};

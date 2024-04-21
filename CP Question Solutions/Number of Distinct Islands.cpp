class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        set<vector<pair<int, int>>> s;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                q.push({i, j});
                grid[i][j] = 1;
                
                int a = -1*i;
                int b = -1*j;
                
                vector<pair<int, int>> v;
                
                while(!q.empty()){
                    pair<int, int> p = q.front();
                    q.pop();
                    
                    int r = p.first;
                    int c = p.second;
                    
                    v.push_back({r+a, c+b});
                    
                    if(r+1 < m && grid[r+1][c] == 1){
                        grid[r+1][c] = 0;
                        q.push({r+1, c});
                    }
                    if(r-1 >= 0 && grid[r-1][c] == 1){
                        grid[r-1][c] = 0;
                        q.push({r-1, c});
                    }
                    if(c+1 < n && grid[r][c+1] == 1){
                        grid[r][c+1] = 0;
                        q.push({r, c+1});
                    }
                    if(c-1 < n && grid[r][c-1] == 1){
                        grid[r][c-1] = 0;
                        q.push({r, c-1});
                    }
                    
                }
                s.insert(v);
                
            }
        }
        return s.size();
    }
};

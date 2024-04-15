class Solution {
  private: 
    int M;
    int N;
  public:
    // Function to find the number of islands.
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid){
        if(i >= M || i < 0 || j >= N || j < 0 || grid[i][j] == '0' || vis[i][j] == 1) return;
        
        vis[i][j] = 1;
        dfs(i+1, j, vis, grid);
        dfs(i-1, j, vis, grid);
        dfs(i, j+1, vis, grid);
        dfs(i, j-1, vis, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m  = grid.size();
        M = m;
        int n  = grid[0].size();
        N = n;
        int res = 0;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfs(i, j, vis, grid);
                    res++;
                }
            }
        }
        return res;
        
    }
};


//queue solution


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));
        queue<vector<int>> q; 

        int res = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '0' || vis[i][j] == 1) continue;
                q.push({i,j});
                vis[i][j] = 1;
                while(!q.empty()){
                    vector<int> v = q.front();
                    q.pop();
                    if(((v[1]+1) < n) && grid[v[0]][v[1]+1] == '1' && vis[v[0]][v[1]+1] == 0) {
                        vis[v[0]][v[1]+1] = 1;
                        q.push({v[0],v[1]+1});
                    }
                    if(((v[1]-1) >= 0) && grid[v[0]][v[1]-1] == '1' && vis[v[0]][v[1]-1] == 0) {
                        vis[v[0]][v[1]-1] = 1;
                        q.push({v[0],v[1]-1});
                    }
                    if(((v[0]+1) < m) && grid[v[0]+1][v[1]] == '1' && vis[v[0]+1][v[1]] == 0) {
                        vis[v[0]+1][v[1]] = 1;
                        q.push({v[0]+1,v[1]});
                    }
                    if(((v[0]-1) >= 0) && grid[v[0]-1][v[1]] == '1' && vis[v[0]-1][v[1]] == 0) {
                        vis[v[0]-1][v[1]] = 1;
                        q.push({v[0]-1,v[1]});
                    }
                }
                res++;
            }
        }
        return res;
    }
};

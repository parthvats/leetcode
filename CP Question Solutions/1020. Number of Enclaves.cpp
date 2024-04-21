class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int count = 0;

        for(int i = 1; i < m-1; i++){
            for(int j = 1; j < n-1; j++){
                if(grid[i][j] == 0) continue;
                int temp = 0;
                q.push({i, j});
                grid[i][j] = 0;
                temp++;
                bool b = false;

                while(!q.empty()){
                    pair<int, int> p = q.front();
                    q.pop();
                    int r = p.first;
                    int c = p.second;

                    if(r+1 < m && grid[r+1][c] == 1){
                        if(r+1 == m-1) b = true; 
                        grid[r+1][c] = 0;
                        q.push({r+1, c});
                        temp++;
                    }
                    if(r-1 >= 0 && grid[r-1][c] == 1){
                        if(r-1 == 0) b = true; 
                        grid[r-1][c] = 0;
                        q.push({r-1, c});
                        temp++;
                    }
                    if(c+1 < n && grid[r][c+1] == 1){
                        if(c+1 == n-1) b = true; 
                        grid[r][c+1] = 0;
                        q.push({r, c+1});
                        temp++;
                    }
                    if(c-1 >= 0 && grid[r][c-1] == 1){
                        if(c-1 == 0) b = true; 
                        grid[r][c-1] = 0;
                        q.push({r, c-1});
                        temp++;
                    }

                }
                if(!b) count += temp;
            }
        }
        return count;
    }
};


// Better Solution

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) if(grid[i][0] == 1) q.push({i, 0});
        for(int i = 0; i < m; i++) if(grid[i][n-1] == 1) q.push({i, n-1});
        for(int i = 0; i < n; i++) if(grid[0][i] == 1) q.push({0, i});
        for(int i = 0; i < n; i++) if(grid[m-1][i] == 1) q.push({m-1, i});

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;

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
            if(c-1 >= 0 && grid[r][c-1] == 1){
                grid[r][c-1] = 0;
                q.push({r, c-1});
            }
        }

        int count = 0;

        for(int i = 1; i < m-1; i++){
            for(int j = 1; j < n-1; j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;


    }
};

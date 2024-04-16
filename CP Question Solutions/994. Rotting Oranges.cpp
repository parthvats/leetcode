class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int min = 0;
        set<pair<int, int>> s;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) s.insert({i,j});
                if(grid[i][j] == 2) {
                    grid[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int sz = q.size();
            bool b = false;
            for(int k = 0; k < sz; k++){
                pair<int, int> p = q.front();
                int r = p.first;
                int c = p.second;
                q.pop();

                if(r+1 < m && grid[r+1][c] == 1){
                    grid[r+1][c] = 0;
                    q.push({r+1,c});
                    if(s.find({r+1,c}) != s.end()) s.erase({r+1,c});
                    b = true;
                }
                if(r-1 >= 0 && grid[r-1][c] == 1){
                    grid[r-1][c] = 0;
                    q.push({r-1,c});
                    if(s.find({r-1,c}) != s.end()) s.erase({r-1,c});
                    b = true;
                }
                if(c+1 < n && grid[r][c+1] == 1){
                    grid[r][c+1] = 0;
                    q.push({r,c+1});
                    if(s.find({r,c+1}) != s.end()) s.erase({r,c+1});
                    b = true;
                }
                if(c-1 >= 0 && grid[r][c-1] == 1){
                    grid[r][c-1] = 0;
                    q.push({r,c-1});
                    if(s.find({r,c-1}) != s.end()) s.erase({r,c-1});
                    b = true;
                }
            }
            if(b) min++;
        }
        if(s.size() > 0) return -1;
        if(min == 0)  return 0;
        return min;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>  vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        
        for(int i = 1; i < m-1; i++){
            for(int j = 1; j < n-1; j++){
                if(mat[i][j] == 'X' || vis[i][j] == 1) continue;
                q.push({i, j});
                vis[i][j] = 1;
                stack<pair<int,int>> s;
                bool b = true;
                
                while(!q.empty()){
                    pair<int, int> p = q.front();
                    q.pop();
                    s.push(p);
                    
                    int r = p.first;
                    int c = p.second;
                    if(r == m-1 || r == 0 || c == n-1 || c == 0)  {
                        b = false;
                    }
                    
                    if(r+1 < m && mat[r+1][c] == 'O' && vis[r+1][c] == 0){
                        vis[r+1][c] = 1;
                        q.push({r+1, c});
                    }
                    if(r-1 >= 0 && mat[r-1][c] == 'O' && vis[r-1][c] == 0){
                        vis[r-1][c] = 1;
                        q.push({r-1, c});
                    }
                    if(c+1 < n && mat[r][c+1] == 'O' && vis[r][c+1] == 0){
                        vis[r][c+1] = 1;
                        q.push({r, c+1});
                    }
                    if(c-1 >= 0 && mat[r][c-1] == 'O' && vis[r][c-1] == 0){
                        vis[r][c-1] = 1;
                        q.push({r, c-1});
                    }
                }
                if(b){
                    while(!s.empty()){
                        pair<int, int> p = s.top();
                        mat[p.first][p.second] = 'X';
                        s.pop();
                    }
                }
                
            }
        }
    }
};

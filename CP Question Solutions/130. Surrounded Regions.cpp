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



// TUF solution

class Solution {
public:
    void bfs(int m, int n, queue<pair<int, int>>& q, vector<vector<int>>& vis, vector<vector<char>>& board){
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            int r = p.first;
            int c = p.second;
            q.pop();

            if(r+1 < m && board[r+1][c] == 'O' && vis[r+1][c] == 0){
                vis[r+1][c] = 1;
                q.push({r+1, c});
            }
            if(r-1 >= 0 &&  board[r-1][c] == 'O' && vis[r-1][c] == 0 ){
                vis[r-1][c] = 1;
                q.push({r-1, c});
            }
            if(c+1 < n && board[r][c+1] == 'O' && vis[r][c+1] == 0){
                vis[r][c+1] = 1;
                q.push({r, c+1});
            }
            if(c-1 >= 0 && board[r][c-1] == 'O' && vis[r][c-1] == 0){
                vis[r][c-1] = 1;
                q.push({r, c-1});
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'X') continue;
            q.push({i,0});
            vis[i][0] = 1;
            bfs(m, n, q, vis, board);
        }
        for(int i = 0; i < m; i++){
            if(board[i][n-1] == 'X' || vis[i][n-1] == 1) continue;
            q.push({i,n-1});
            vis[i][n-1] = 1;
            bfs(m, n, q, vis, board);
        }
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'X' || vis[0][i] == 1) continue;
            q.push({0,i});
            vis[0][i] = 1;
            bfs(m, n, q, vis, board);
        }
        for(int i = 0; i < n; i++){
            if(board[m-1][i] == 'X' || vis[m-1][i] == 1) continue;
            q.push({m-1,i});
            vis[m-1][i] = 1;
            bfs(m, n, q, vis, board);
        }

        for(int i = 1; i < m-1; i++){
            for(int j = 1; j < n-1; j++){
                if(board[i][j] == 'X' || vis[i][j] == 1) continue;
                else{
                    board[i][j] = 'X';
                    vis[i][j] = 1;
                }
            }
        }
        
    }
};

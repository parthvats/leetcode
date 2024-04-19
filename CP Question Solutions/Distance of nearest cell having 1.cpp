// TIME LIMIT EXCEEDED 

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m = grid.size();
	    int n = grid[0].size();
	    
	    vector<vector<int>> res(m, vector<int>(n,0));

	    
	    for(int i= 0; i < m; i++){
	        for(int j = 0; j < n; j++){
	            if(grid[i][j] == 1) continue;
	            vector<vector<int>> vis(m, vector<int>(n,0));
	            queue<pair<int, int>> q;
	            q.push({i, j});
	            int dis = 0;
	            
	            while(!q.empty()){
	                int sz = q.size();
	                bool b = false;
	                
	                for(int k = 0; k < sz; k++){
	                    pair<int, int> p = q.front();
    	                q.pop();
    	                int r = p.first;
    	                int c = p.second;
                        vis[r][c] = 1;
    	                if((r+1 < m && grid[r+1][c] == 1) || (r-1 >=0 && grid[r-1][c] == 1) || (c+1 < n && grid[r][c+1] == 1) || (c-1 >=0 && grid[r][c-1] == 1)){   
    	                    b = true;
    	                    break;
    	                }
	                    if(r+1 < m && vis[r+1][c] == 0){
	                        q.push({r+1, c});
    	                }
    	                if(r-1 >= 0 && vis[r-1][c] == 0){
    	                    q.push({r-1, c});
    	                }
    	                if(c+1 < n && vis[r][c+1] == 0){
    	                    q.push({r, c+1});
    	                }
    	                if(c-1 >= 0 && vis[r][c-1] == 0){
    	                    q.push({r, c-1});
    	                }
	                }
	                dis ++;
	                if(b) break;
	            }
	            res[i][j] = dis;
	        }
	    }
	    return res;
	}
};

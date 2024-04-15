class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int color) {
        if(image[i][j] == color) return image;
        int m = image.size();
        int n = image[0].size();
        int c = image[i][j];        

        queue<pair<int, int>> q;
        q.push({i, j});

        while(!q.empty()){
            pair<int, int> p = q.front();
            i = p.first;
            j = p.second;
            image[i][j] = color;
            q.pop();

            if(j+1 < n && image[i][j+1] == c) {
                image[i][j+1] = color;
                q.push({i, j+1});
            }
            if(j-1 >= 0 && image[i][j-1] == c){
                image[i][j-1] = color;
                q.push({i, j-1});
            }
            if(i+1 < m && image[i+1][j] == c){
                image[i+1][j] = color;
                q.push({i+1, j});
            }
            if(i-1 >= 0 && image[i-1][j] == c) {
                image[i-1][j] = color;
                q.push({i-1, j});
            }
        }
        return image;
    }
};

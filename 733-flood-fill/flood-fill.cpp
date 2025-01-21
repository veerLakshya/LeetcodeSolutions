class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        vector<int> dx = {1,-1,0,0}, dy = {0,0,-1,1};
        auto h = [&](int i, int j,int col, auto self) -> void{
            image[i][j] = color;
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x >= 0 && y >= 0 && x < m && y < n && image[x][y] == col) self(x, y, col, self);
            }
        };
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         if(image[i][j] != color) h(i)
        //     }
        // }
        if(image[sr][sc] != color) h(sr, sc,image[sr][sc],  h);
        return image;
    }
};
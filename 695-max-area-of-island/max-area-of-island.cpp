class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

        auto h = [&](int i, int j, auto &self)->int{
            grid[i][j] = 0;
            int ans = 1;
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) ans += self(x, y, self);
            }
            return ans;
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int cur = h(i, j, h);
                    ans = max(ans, cur);
                    // cout << i << " "<< j <<" "<< cur << endl;
                    // for(auto i: grid){
                    //     for(auto j: i) cout <<j;
                    //     cout <<endl;
                    // }
                }
            }
        }
        return ans;
    }
};
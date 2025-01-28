class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        vector<int> dx = {0,0,1,-1}, dy = {1, -1, 0, 0};
        auto dfs = [&](int i, int j, auto self) -> int{
            vis[i][j] = 1;
            int cur = grid[i][j];
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || !grid[x][y]) continue;
                cur += self(x,y,self);
            }
            return cur;
        };
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] && !vis[i][j]) ans = max(ans, dfs(i,j, dfs));
            }
        }
        return ans;
    }
};
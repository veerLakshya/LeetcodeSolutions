class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]) {
                    q.push({i,j});
                    grid[i][j] = 0;
                }
                else{
                    grid[i][j] = -1;
                }
            }
        }
        while(q.size()){
            auto [i, j] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != -1)continue;
                grid[x][y] = grid[i][j] + 1;
                q.push({x,y});
            }
        }
        int ans = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    ans = max(ans, grid[i][j]);
                }
            }
        }
        return ans;
    }
};
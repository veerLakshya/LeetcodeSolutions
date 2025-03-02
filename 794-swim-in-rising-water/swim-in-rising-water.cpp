class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = grid[0][0], right = n * n  + 1, ans = n * n + 1;

        auto isvalid = [&](int x, int y)->bool{
            return (x >= 0 && y >= 0 && x < n && y < n);
        };
        vector<int> dx = {0,0,1,-1}, dy = {1,-1,0,0};

        function<bool(int, int, int, vector<vector<int>>&)> dfs = 
        [&](int i, int j, int waterHeight, vector<vector<int>>& vis)->bool{
            if(i == n - 1 && j == n - 1)return true;
            vis[i][j] = 1;
            for(int k = 0; k < 4; k++){
                int x = dx[k] + i;
                int y = dy[k] + j;
                if(isvalid(x,y) && !vis[x][y] && grid[x][y] <= waterHeight){
                    if(dfs(x,y,waterHeight, vis))return true;
                }
            }
            return false;
        };

        function<bool(int)> possible = [&](int height)->bool{
            vector<vector<int>> vis(n, vector<int> (n,0));
            return dfs(0, 0, height, vis);
        };
        while(left <= right){
            int mid = (left+right)/2;
            if(possible(mid)){
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        vector<int> dx = {1,-1,0, 0}, dy = {0,0,1,-1};
        vector<vector<int>> vis = grid;
        for(auto &i: vis) for(auto &j: i) j = 0;
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        while(q.size()){
            pair<pair<int,int>,int> a = q.front();
            ans = max(ans, a.second);
            q.pop();
            for(int k = 0; k < 4; k++){
                int x = a.first.first + dx[k];
                int y = a.first.second + dy[k];
                if(x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1 && !vis[x][y]){
                    vis[x][y] = 1;
                    q.push({{x,y}, a.second + 1});
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j])return -1;
            }
        }
        return ans;
    }
};
class Solution {
public:
void print(vector<vector<int>>& a){
        int n = a.size(), m = a[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)cout << a[i][j] <<" ";
            cout << endl; 
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int> dx = {1,-1,0,0}, dy = {0,0,-1,1};
        vector<vector<int>> vis = grid;
        for(auto &i: vis) for(auto &j: i) j = 0;

        auto helper = [&](int i, int j, auto self)->void{
            vis[i][j] = 1;
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] && !vis[x][y]) self(x, y, self);
            }
        };


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i == 0 || j == 0 || i ==n-1 || j == m-1) && grid[i][j]) helper(i,j,helper);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j]) ans++;
            }
        }
        return ans;
    }
};
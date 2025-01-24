class Solution {
public:
    void print(vector<vector<int>>& a){
        int n = a.size(), m = a[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)cout << a[i][j] <<" ";
            cout << endl; 
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<int> dx = {1,-1,0,0}, dy = {0,0,-1,1};
        vector<vector<int>> dp = matrix;
        for(auto &i: dp) for(auto &j: i) j = -1;
        
        
        auto bfs = [&](int i, int j, auto self) -> int{
            if(dp[i][j] != -1) return dp[i][j];
            int ans = 1;
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x >= 0 && x < n && y>=0 && y < m && matrix[x][y] > matrix[i][j]){
                    if (dp[x][y] != -1) ans = max(ans, dp[x][y]+1);
                    else ans = max(ans, self(x, y, self) + 1);
                }
            }
            return dp[i][j] = ans;
        };
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dp[i][j] == -1) bfs(i,j,bfs);
                ans = max(ans, dp[i][j]);
            }
        }
        // print(dp);
        return ans;
    }
};
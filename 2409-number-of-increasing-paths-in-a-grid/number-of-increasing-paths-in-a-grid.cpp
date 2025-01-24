class Solution {
public:
    void print(vector<vector<int>>& a){
        int n = a.size(), m = a[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)cout << a[i][j] <<" ";
            cout << endl; 
        }
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<int> dx = {1,-1,0,0}, dy = {0,0,-1,1};
        long long n = grid.size(), m = grid[0].size(), mod = 1e9 + 7;
        vector<vector<long long>> dp(n, vector<long long> (m,-1));
        auto dfs = [&](long long i, long long j, auto self) -> long long{
            if(dp[i][j] != -1) return dp[i][j];
            long long cur = 1;
            for(long long k = 0; k < 4; k++){
                long long x = i + dx[k];
                long long y = j + dy[k];
                if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] > grid[i][j]){
                    cur += self(x, y, self);
                    cur %= mod;
                }
            }
            return dp[i][j] = cur;
        };
        dfs(0, 0, dfs);
        long long ans = 0;
        // print(dp);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) if(dp[i][j] != -1) ans += dp[i][j];
            else ans+= dfs(i, j, dfs);
            ans %= mod;
        }
        return ans;
    }
};
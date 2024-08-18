class Solution {
public:
    int dp[202][202];
    int helper(int i, int j, vector<vector<int>>& a){
        if(i == 0 && j == 0) return dp[0][0] = a[0][0];
        if(i < 0 || j < 0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = a[i][j] + min(helper(i-1, j, a), helper(i, j-1, a)); 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        memset(dp, -1, sizeof(dp));
        helper(n-1, m-1, grid);
        return dp[n-1][m-1];
    }
};
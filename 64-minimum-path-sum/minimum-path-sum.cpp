class Solution {
public:
    // int helper(int n,int m,int i,int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //     if(i>=n||j>=m)return INT_MAX;
    //     if(i==n-1 && j==m-1) return grid[n-1][m-1];
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     dp[i][j]=grid[i][j]+min(helper(n,m,i,j+1,grid,dp),helper(n,m,i+1,j,grid,dp));
    //     return dp[i][j];
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int> (m+1,-1));
        dp[n-1][m-1]=grid[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1)continue;
                else if(i==n-1)dp[i][j]= grid[i][j]+dp[i][j+1];
                else if(j==m-1)dp[i][j]= grid[i][j]+dp[i+1][j];
                else dp[i][j]= grid[i][j]+min(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};
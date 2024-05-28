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
        for(int i=n-2;i>=0;i--){
            dp[i][m-1]=grid[i][m-1]+dp[i+1][m-1];
        }
        for(int i=m-2;i>=0;i--){
            dp[n-1][i]=grid[n-1][i]+dp[n-1][i+1];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j]=min(dp[i][j+1],dp[i+1][j])+grid[i][j];
            }
        }
        return dp[0][0];
    }
};
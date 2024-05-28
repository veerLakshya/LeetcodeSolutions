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
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)dp[i][j]=grid[i][j];
                else{
                    int up = grid[i][j];
                    int left = grid[i][j];
                    if(i>0)up+=dp[i-1][j];
                    else up+=1e9;
                    if(j>0)left+=dp[i][j-1];
                    else left+=1e9;
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};
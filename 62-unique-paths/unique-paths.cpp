class Solution {
public:
    int N,M;
    int helper(int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0)return 1;
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int res=0;
        res+=helper(i-1,j,dp);
        res+=helper(i,j-1,dp);
        return dp[i][j]=res;
    }

    int uniquePaths(int m, int n) {
        N = n, M = m;
        vector<vector<int>> dp(n,vector<int>(m, - 1));
        return helper(n - 1,m - 1,dp);
        
    }
};
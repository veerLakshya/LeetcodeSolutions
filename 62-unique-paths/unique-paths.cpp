class Solution {
public:
    long long dp[101][101];
    long long helper(int i, int j){
        if(i==0 && j==0) return dp[0][0] = 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return  dp[i][j];
        return dp[i][j] = helper(i-1, j) + helper(i, j-1);
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1, sizeof(dp));
        helper(n,m);
        return dp[n-1][m-1];
    }
};
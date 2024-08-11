class Solution {
public:
    int helper(int n, vector<int>& dp){
        if(n==1) return dp[n] = 1;
        if(n==2) return dp[2] = 2;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = helper(n-1,dp)+helper(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp (n+1, -1);
        helper(n, dp);
        return dp[n];
    }
};
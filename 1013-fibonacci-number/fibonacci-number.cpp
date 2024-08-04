class Solution {
public:
    int dp[32];
    int helper(int n){
        if(n== 1 || n==0) return n;
        if(dp[n]!= -1) return dp[n];
        return dp[n] = helper(n-1) + helper(n-2);
    }
    int fib(int n) {
        for(int i = 0; i<=n; i++) dp[i] = -1;
        return helper(n);
    }
};
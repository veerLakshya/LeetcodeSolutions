class Solution {
public:
    int mod = 1e9 + 7;
    int dp[10069][7][7];
    int helper(int len, int cur, int last){
        if(len < 0) return 0;
        if(len == 0) return 1;
        if(dp[len][cur][last] != -1) return dp[len][cur][last];
        int ways = 0;
        for(int i = 1; i <= 6; i++){
            if(i == cur || i == last) continue;
            if(gcd(cur, i) == 1) ways += helper(len - 1, i, cur);
            ways %= mod;
        }
        return dp[len][cur][last] = ways % mod;
    }
    int distinctSequences(int n) {
        if(n == 1) return 6;
        memset(dp, -1, sizeof dp);
        int ans = 0;
        for(int i = 1; i <= 6; i++){
            for(int j = 1; j <= 6; j++){
                if(i == j) continue;
                if(gcd(i,j) == 1) ans += helper(n - 2, i, j);
                ans %= mod;
            }
        }
        return ans;
    }
};
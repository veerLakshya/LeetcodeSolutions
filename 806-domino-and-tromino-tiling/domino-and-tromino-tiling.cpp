class Solution {
public:
    long long dp[1069][2], mod = 1e9 + 7;
    long long helper(int i, int prev, int n){
        // base case - last index with 0 openning
        if(i == n) return (prev == 0 ? 1 : 0);

        if(dp[i][prev] != -1) return dp[i][prev];

        // no vertical if opening else 1 way
        int v = (prev ? 0 : helper(i + 1, 0, n));
        // 1 way to place 2 horizontally if 0 openning on prev
        int h2 = prev != 0 || i + 2 > n ? 0 : helper(i + 2, 0, n);
        // 1 way to place 1 horizontally if 1 openning on prev
        int h1 = prev == 0 ? 0 : helper(i + 1, 1, n);
        // to place tromino - if openning on last then only 1 way else two ways
        int t = prev == 0 ? (i + 2 > n ? 0 : 2 * helper(i + 2, 1, n)) : helper(i + 1, 0, n);
        return dp[i][prev] = (v%mod + h2%mod + h1%mod + t%mod)%mod;
    }
    int numTilings(int n) {
        memset(dp, -1, sizeof dp);
        return helper(0,0,n);
    }
};
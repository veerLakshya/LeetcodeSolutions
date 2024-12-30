class Solution {
public:
    int dp[(int)1e6 + 1];
    int l, h, z, o, mod = 1e9 + 7;
    int helper(int i){
        if(dp[i] != -1) return dp[i];
        if (i == 0) return 1;
        int cur = 0;
        if(i >= o) cur += helper(i - o);
        cur %= mod;
        if(i >= z) cur += helper(i - z);
        cur %= mod;
        return dp[i] = cur;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        l = low, h = high, z = zero, o = one;
        memset(dp, -1, sizeof (dp));
        int ans = 0;
        // helper(high);
        for(int i = low; i <= high; i++) ans += helper(i), ans %= mod;
        return ans;
    }
};
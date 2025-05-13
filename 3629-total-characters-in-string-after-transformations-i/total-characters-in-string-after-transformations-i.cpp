class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(t + 2, vector<int> (26, 0));
        for(int i = 0; i < 26; i++) dp[0][i] = 1;
        for(int i = 1; i <= t; i++){
            for(int j = 0; j < 25; j++){
                dp[i][j] = dp[i - 1][j + 1] % mod;
            }
            dp[i][25] = (dp[i-1][0] % mod + dp[i - 1][1] % mod) % mod;
        }

        int ans = 0;
        for(auto i: s) ans = (ans + dp[t][i - 'a']) % mod;
        return ans;
    }
};
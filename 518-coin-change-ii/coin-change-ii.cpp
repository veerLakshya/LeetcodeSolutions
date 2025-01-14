class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount+1, 0);
        int mod = 1e9 + 7;
        dp[0] = 1;
        for(auto i: coins){
            for(int j = 1; j <= amount; j++){
                if(j - i >= 0) dp[j] += dp[j-i];
                // dp[j] %= mod;
            }
        }
        return dp[amount];
    }
};
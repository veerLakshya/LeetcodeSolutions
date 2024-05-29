class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e9); // initialized with very high values initially
        // dp[k] = minimum number of coins required to construct a sum of k
        // dp[k] = min(dp[k-ai]) + 1 : i goes from 1  to n
        dp[0] = 0; // base case
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return (dp[amount] != 1e9 ? dp[amount] : -1);
    }
};
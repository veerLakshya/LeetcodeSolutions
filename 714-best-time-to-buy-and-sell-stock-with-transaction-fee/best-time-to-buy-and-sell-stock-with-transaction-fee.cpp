class Solution {
public:
    int h(int i, int j, int& fee, vector<int>& prices, vector<vector<int>>& dp){
        if(i >= prices.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        // j = 1 : i own a stock, so i can sell or pass
        // j = 0 : i dont own a stock, so i can buy or pass
        if(j){
            int op1 = prices[i] + h(i+1, !j, fee, prices, dp);
            int op2 = h(i+1, j, fee, prices, dp);
            return dp[i][j] = max(op1, op2);
        }
        else{
            int op1 = -prices[i] - fee + h(i + 1, !j, fee, prices, dp);
            int op2 = h(i+1, j, fee, prices, dp); 
            return dp[i][j] = max(op1, op2);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return h(0, 0, fee, prices, dp);
    }
};
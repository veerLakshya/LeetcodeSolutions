class Solution {
public:
    int dp[1001][2][101];
    int h(int i, int buy, int k, vector<int>& prices){
        if(i == prices.size() || k == 0)  return 0;

        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        //i own a stock and need to sell it
        if(buy){
            int op1 = prices[i] + h(i + 1, !buy, k - 1, prices);
            int op2 = h(i + 1, buy, k, prices);
            return dp[i][buy][k] = max(op1, op2);
        }
        //i dont own a stock so i will try to buy or pass
        else{
            int op1 = -prices[i] + h(i + 1, !buy, k, prices);
            int op2 = h(i+1, buy, k, prices);
            return dp[i][buy][k] = max(op1, op2);
        }
        return 1;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return h(0, 0, k, prices);
    }
};
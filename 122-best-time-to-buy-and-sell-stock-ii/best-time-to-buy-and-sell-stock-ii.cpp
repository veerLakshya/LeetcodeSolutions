class Solution {
public:
    int h(int i, int j, vector<int>& a, vector<vector<int>>& dp){
        if(i == a.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(j){
            // since i own a stock, i can either sell or pass
            int op1 = a[i] + h(i+1, !j, a, dp);
            int op2 = h(i+1, j, a, dp);
            return dp[i][j] = max(op1, op2);
        }
        else{
            int op1 = -a[i] + h(i+1, !j, a, dp);
            int op2 = h(i+1, j, a, dp);
            return dp[i][j] = max(op1, op2);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return h(0, 0, prices, dp);
    }
};
class Solution {
public:
    int dp[100002][2][3];
    int h(int i, int own, int t, vector<int>& prices){
        if(i == prices.size() || t == 0) return 0;
        if(dp[i][own][t] != -1) return dp[i][own][t];

        if(own){
            int op1 = prices[i] + h(i+1, !own, t-1, prices);
            int op2 = h(i+1, own, t, prices);
            return dp[i][own][t] = max(op1, op2);
        }
        else{
            int op1 = -prices[i] + h(i+1, !own, t, prices);
            int op2 = h(i+1, own, t, prices);
            return dp[i][own][t] = max(op1, op2); 
        }
        return 1;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return h(0, 0, 2, prices);
    }
};
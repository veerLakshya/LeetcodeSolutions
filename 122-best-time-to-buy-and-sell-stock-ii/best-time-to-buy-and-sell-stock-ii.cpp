class Solution {
public:
    int h(int ind, bool needtobuy, auto& a){
        if(ind >= a.size()) return 0;
        if(needtobuy){
            int op1 = -a[ind] + h(ind + 1, 0, a);
            int op2 = h(ind + 1, 1, a);
            return max(op1, op2);
        }
        else{
            int op1 = a[ind] + h(ind + 1, 1, a);
            int op2 = h(ind + 1, 0, a);
            return max(op1, op2);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        for(int i = 0; i < n; i++){
            if(i == 0){
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
            }
            else{
                dp[i][0] = max(dp[i-1][0],prices[i] + dp[i-1][1]);
                dp[i][1] = max(dp[i-1][1], dp[i-1][0]- prices[i]);
            }
        }
        return dp[n-1][0];

        // return h(0,1,prices);
    }
};
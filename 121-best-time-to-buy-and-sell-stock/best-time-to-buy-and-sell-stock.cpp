class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > mini) ans = max(ans, prices[i]-mini);
            else mini = min(mini, prices[i]);
        }
        return ans;
    }
};
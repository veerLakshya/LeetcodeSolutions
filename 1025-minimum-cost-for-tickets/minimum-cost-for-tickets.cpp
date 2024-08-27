class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = *max_element(days.begin(),days.end());
        int dp[n+1];
        dp[0] = 0;
        int x = 0;
        for(int i = 1; i <= n; i++){
            if( i != days[x]){ 
                dp[i] = dp[i-1];
                continue;
            }
            int op1 = costs[0] + dp[max(0,i-1)];
            int op2 = costs[1] + dp[max(0,i-7)];
            int op3 = costs[2] + dp[max(0,i-30)];
            dp[i] = min(op1, min(op2,op3));
            x++;
        }
        return dp[n];
    }
};
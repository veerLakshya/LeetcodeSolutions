class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int dp[n][2];
        dp[n-1][0] = 0, dp[n-1][1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            dp[i][1] = nums[i] + dp[i+1][0];
            dp[i][0] = max(dp[i+1][1],dp[i+1][0]);
        }
        return max(dp[0][0],dp[0][1]);
    }
};
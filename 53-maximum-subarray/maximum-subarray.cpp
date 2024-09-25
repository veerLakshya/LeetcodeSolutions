class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0] ;
        int ans = dp[0];
        for(int i = 1; i < n; i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            // if(dp[i] < 0) dp[i] = 0;
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
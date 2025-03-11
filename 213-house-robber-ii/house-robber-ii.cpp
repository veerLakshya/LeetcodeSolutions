class Solution {
public:
    int rob(vector<int>& nums) {
        int ans1 = 0, ans2 = 0, n = nums.size();
        if(n <= 3) return *max_element(nums.begin(),nums.end());

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < n - 1; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        ans1 = dp[n-2];
        dp.assign(n,0);
        dp[1] = nums[1];
        dp[2] = max(nums[1],nums[2]);
        for(int i = 3; i < n; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        } 
        ans2 = dp[n-1];
        return max(ans1, ans2);
    }
};
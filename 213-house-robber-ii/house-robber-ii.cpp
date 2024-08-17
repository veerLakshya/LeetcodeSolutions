class Solution {
public:
    int n;
    int f(int i,int flag,vector<int> &nums,vector<vector<int>> &dp){
        if(i >= n) return 0;
        if(i == n - 1) return flag == 1 ? 0 : nums[n - 1];
        if(dp[i][flag] != -1) return dp[i][flag];
        int a1 = f(i + 1,flag,nums,dp);
        int a2 = nums[i] + f(i + 2,(i == 0 ? 1 : flag),nums,dp);

        return dp[i][flag] = max(a2,a1);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,0,nums,dp);
    }
};
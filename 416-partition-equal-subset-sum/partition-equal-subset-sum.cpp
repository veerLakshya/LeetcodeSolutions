class Solution {
public:
    int dp[201][20001];
    int n, total;
    bool helper(int ind, int cur, auto& nums){
        if(cur == total) return 1;
        if(ind == n) return 0;
        if(dp[ind][cur] != -1) return dp[ind][cur];
        return dp[ind][cur] = helper(ind + 1, cur + nums[ind], nums)||helper(ind + 1, cur, nums); 
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size(), total = accumulate(nums.begin(), nums.end(), 0);
        memset(dp, -1, sizeof dp);
        if(total%2)return 0;
        total /= 2;
        return helper(0, 0, nums);
    }
};
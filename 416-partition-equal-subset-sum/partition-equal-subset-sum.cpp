class Solution {
public:
    int dp[201][20001];
    bool h(int ind, int sum, vector<int>& a){
        if(sum == 0) return 1;
        if(ind < 0 || sum < 0) return 0;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        bool take = h(ind - 1, sum - a[ind], a);
        bool nottake = h(ind -1, sum, a);
        return dp[ind][sum] = take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return 0;
        memset(dp, -1, sizeof dp);
        return h(nums.size()-1, sum/2, nums);
    }
};
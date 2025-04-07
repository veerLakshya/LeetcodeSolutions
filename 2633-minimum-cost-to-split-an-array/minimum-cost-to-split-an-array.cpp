class Solution {
public:
    int split[1001][1001], dp[1001];
    int helper(int ind, int k, auto& nums){
        if(ind >= nums.size()) return 0;

        if(dp[ind] != -1) return dp[ind];
        int cost = INT_MAX;
        for(int i = ind; i < nums.size(); i++){
            // split from ind to i and call function for the remaining array
            int opt = k + split[ind][i] + helper(i+1, k, nums);
            cost = min(cost, opt);
        }
        return dp[ind] = cost;
    }
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            unordered_map<int,int> freq;
            int val = 0;
            for(int j = i; j < n; j++){
                freq[nums[j]]++;
                if(freq[nums[j]] == 2) val+=2;
                else if(freq[nums[j]] > 2) val++;
                split[i][j] = val;
            }
        }
        memset(dp, -1, sizeof dp);
        return helper(0, k, nums);
    }
};
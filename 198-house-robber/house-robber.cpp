class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        // state
        // dp[i] = max sum from 0th element to ith element 
        vector<int> dp(n);
        
        // transition
        // dp[i] = max(nums[i] + dp[i-2], dp[i-1])

        // base case
        // dp[0] = arr[0], dp[1] = max(arr[0],arr[1])
        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);

        for(int i=2;i<n;i++){
            dp[i]= max(nums[i]+dp[i-2], dp[i-1]);
        }
        // final subproblem
        // dp[0] = max sum from 0th element to last element
        return dp[n-1];
    }
};
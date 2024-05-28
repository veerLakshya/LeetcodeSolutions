class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        // state
        // dp[i] = max sum from ith element to last element 
        vector<int> dp(n);
        
        // transition
        // dp[i] = max(nums[i] + dp[i+2], dp[i+1])

        // base case
        // dp[n-1] = arr[n-1], dp[n-2] = max(arr[n-1],arr[n-2])
        dp[n-1]=nums[n-1];
        dp[n-2]=max(nums[n-1],nums[n-2]);

        for(int i=n-3;i>=0;i--){
            dp[i]= max(nums[i]+dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
};
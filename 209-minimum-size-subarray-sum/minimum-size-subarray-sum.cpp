class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MAX, start = 0, end =0;

        while(end!=n){
            sum+=nums[end];
            while(sum-nums[start]>=target){
            // cout<<sum<<" ";
                sum-=nums[start];

                start++;
            }
            if(sum>=target)ans = min(ans,end-start+1);
            end++;
            // cout<<sum<<" ";
        }
        return ans==INT_MAX?0:ans;
    }
};
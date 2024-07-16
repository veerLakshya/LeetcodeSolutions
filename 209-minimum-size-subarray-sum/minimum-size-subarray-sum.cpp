class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MAX, i = 0, j =0;

        while(i!=n){
            while(sum<target && j<n){
                sum+=nums[j];
                j++;
            }
            if(sum>=target)
            ans= min(ans,j-i);
            sum-=nums[i];
            i++;
        }
        return ans==INT_MAX?0:ans;
    }
};
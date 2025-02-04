class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int cnt = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]) cnt = 0;
            cnt += nums[i];
            ans = max(ans, cnt);
        }
        return ans;
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int last = nums[0];
        int prev = last;
        if(nums.size() > 1) prev = max(prev, nums[1]);
        for(int i = 2; i < nums.size(); i++){
            int curr = max(last + nums[i], prev);
            last = prev;
            prev = curr;
        }
        return prev;
    }
};
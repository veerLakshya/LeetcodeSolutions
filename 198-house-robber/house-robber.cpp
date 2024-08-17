class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int last = nums[0];
        int prev = last;
        if(n>1) prev = max(prev, nums[1]);
        for(int i = 2; i < n; i++){
            int curr = max(last + nums[i], prev);
            last = prev;
            prev = curr;
        }
        return prev;
    }
};
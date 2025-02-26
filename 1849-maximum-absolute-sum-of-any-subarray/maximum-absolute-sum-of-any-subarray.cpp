class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0, mini = INT_MAX, cur = 0;
        for(auto i: nums){
            if(cur + i > 0) cur += i;
            else cur = 0;
            maxi = max(maxi, cur);
        }
        cur = 0;
        for(int i : nums){
            if(cur + i < 0) cur += i;
            else cur = 0;
            mini = min(mini, cur);
        }
        return max(maxi, abs(mini));
    }
};
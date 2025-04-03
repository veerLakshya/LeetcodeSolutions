class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long n = nums.size(), ans = 0, maxl = 0, maxd = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, (long long)(maxd*nums[i]));
            maxd = max(maxd, (long long)(maxl - nums[i]));
            maxl = max(maxl, (long long)nums[i]);
        }
        return ans;
    }
};
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long ans =  0, n = nums.size();
        long long total = 0, cur = 0;
        for(int i = 0; i < n; i++) total += nums[i];
        for(int i = 0; i < n - 1; i++){
            total -= nums[i];
            cur += nums[i];
            ans += (cur >= total);
        }
        return ans;
    }
};
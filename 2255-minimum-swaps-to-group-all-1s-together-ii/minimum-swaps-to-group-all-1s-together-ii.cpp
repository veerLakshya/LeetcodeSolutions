class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0, minswaps = INT_MAX;
        for (auto i : nums)
            k += i;
        int curr = 0, end = 0;

        for (int start = 0; start < n; start++) {
            while (end - start < k) {
                curr += nums[end % n];
                end++;
            }
            minswaps = min(minswaps, k - curr);
            curr -= nums[start];
        }
        return minswaps;
    }
};
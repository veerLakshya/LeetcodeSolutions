class Solution {
public:
    int getFactor(int n) {
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return i;
        }
        return n;
    }
    int minOperations(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                if (nums[i] > nums[i + 1]) {
                    nums[i] = getFactor(nums[i]);
                    if (nums[i] > nums[i + 1]) return -1;
                    ans++;
                }
            }
        }
        return ans;
    }
};
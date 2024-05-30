class Solution {
public:
    int cnt = 0;
    void helper(int i, int n, int sum, int x, vector<int>& arr) {
        if (i == n) {
            if (sum == x) {
                cnt++;
            }
            return;
        }
        helper(i + 1,n, sum - arr[i],x, arr);
        helper(i + 1,n, sum + arr[i],x, arr);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        helper(0, nums.size(), 0, target, nums);
        return cnt;
    }
};
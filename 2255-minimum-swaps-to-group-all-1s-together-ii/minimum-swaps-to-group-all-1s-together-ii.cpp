class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), k = accumulate(nums.begin(),nums.end(),0); 
        int curr = 0, end = 0, ans = INT_MAX;;

        for (int start = 0; start < n; start++) {
            while (end - start < k) {
                curr += nums[end % n];
                end++;
            }
            ans = min(ans, k - curr);
            curr -= nums[start];
        }
        return ans;
    }
};
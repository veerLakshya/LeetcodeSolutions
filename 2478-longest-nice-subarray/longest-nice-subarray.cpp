class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int bits = 0;
        int left = 0, n = nums.size(), ans = 1;
        for(int right = 0; right < n; right++){
            while((bits & nums[right]) != 0){
                bits ^= nums[left];
                left++;
            }
            bits |= nums[right];
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
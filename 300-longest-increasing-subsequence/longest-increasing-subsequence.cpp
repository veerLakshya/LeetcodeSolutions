class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> a(n,0);
        for(int i = 0; i < n; i++){
            a[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]) a[i] = max(a[i], a[j] + 1);
            }
        }
        for(auto i: a) ans = max(ans, i);
        return ans;
    }
};
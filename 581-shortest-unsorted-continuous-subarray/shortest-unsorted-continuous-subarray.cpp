class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> a = nums;
        sort(a.begin(),a.end());
        int ans = nums.size();
        if(a == nums) return 0;
        int i = 0;
        while(i < nums.size() && nums[i] == a[i]) ans--, i++;
        i = nums.size() - 1;
        while(i >= 0 && nums[i] == a[i]) ans--, i--;
        return ans;
    }
};
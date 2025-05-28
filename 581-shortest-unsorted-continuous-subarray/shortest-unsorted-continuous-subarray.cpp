class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());
        int l = -1, r = -2;
        for(int i = 0; i < n; i++){
            if(nums[i] != temp[i] && l == -1){
                l = i;
            }
            if(nums[i] != temp[i]) r = i;
        }
        return r - l + 1;
    }
};
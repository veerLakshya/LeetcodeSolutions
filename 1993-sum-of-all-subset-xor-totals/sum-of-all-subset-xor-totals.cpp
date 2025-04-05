class Solution {
public:
    int ans = 0;
    void h(int ind, int cur, vector<int>& nums){
        if(ind == nums.size()){
            ans += cur;
            return;
        }
        h(ind+1, cur^nums[ind], nums);
        h(ind+1, cur, nums);
    }
    int subsetXORSum(vector<int>& nums) {
        h(0, 0, nums);
        return ans;
    }
};
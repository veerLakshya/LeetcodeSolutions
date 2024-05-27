class Solution {
public:
vector<vector<int>> ans;
vector<int> cur_subset;
    void solve(int i,vector<int> & nums){
        if(i==nums.size()){
            ans.push_back(cur_subset);
            return;
        }
        solve(i+1,nums);
        cur_subset.push_back(nums[i]);
        solve(i+1,nums);
        cur_subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,nums);
        return ans; 
    }
};
class Solution {
public:
set<vector<int>> st;
    vector<vector<int>> ans;
    vector<int> curr_subset;
    void solve(int i,vector<int> & nums){
        if(i==nums.size()){
            if(!st.contains(curr_subset)){
                st.insert(curr_subset);
            ans.push_back(curr_subset);
            }
            return;
        }
        solve(i+1,nums);
        curr_subset.push_back(nums[i]);
        solve(i+1,nums);
        curr_subset.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(0,nums);
        return ans;
    }
};
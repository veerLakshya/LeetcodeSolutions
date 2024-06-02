class Solution {
public:
    int n;
    vector<vector<int>> all_ans;
    vector<int> ans;
    void helper(int start, int curr_sum, int target,vector<int> nums ){
        if(curr_sum>target )return;
        if(curr_sum==target){
            all_ans.push_back(ans);
            return;
        }
        for(int i=start;i<n;i++){
            ans.push_back(nums[i]);
            helper(i, curr_sum+nums[i],target,nums);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        helper(0, 0,target,candidates);
        return all_ans;
    }
};
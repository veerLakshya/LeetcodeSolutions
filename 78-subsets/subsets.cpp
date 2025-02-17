class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void helper(int ind, vector<int> cur, vector<int>& a){
        if(ind == n){
            ans.push_back(cur);
            return;
        }
        helper(ind + 1, cur, a);
        cur.push_back(a[ind]);
        helper(ind + 1, cur, a);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> cur;
        helper(0, cur, nums);
        return ans;
    }
};
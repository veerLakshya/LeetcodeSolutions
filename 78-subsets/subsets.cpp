class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int mask = 0;
        for(int mask = 0; mask < (1 << nums.size()); mask++){
            vector<int> cur;
            for(int j = 0; j < nums.size(); j++){
                if( mask & (1<<j)) cur.push_back(nums[j]);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
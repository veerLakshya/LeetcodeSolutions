class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        for(int i = 0; i < n - 2; i++){
            if(i == 0 || nums[i] != nums[i-1]){
                int l = i + 1, r = n - 1;
                while(l < r){
                    if(nums[l] + nums[r] + nums[i] == 0){
                        vector<int> cur;
                        cur.push_back(nums[i]);
                        cur.push_back(nums[l]);
                        cur.push_back(nums[r]);
                        ans.insert(cur);
                        l++;
                        r--;
                    }
                    else if (nums[l] + nums[r] + nums[i] > 0) r--;
                    else l++;
                }
            }
        }
        vector<vector<int>> _a;
        for(auto i: ans) _a.push_back(i);
        return _a;
    }
};
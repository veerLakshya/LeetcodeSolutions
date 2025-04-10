class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(auto i: nums) st.insert(i);
        int i = 0, n= nums.size();
        if(n == 0 || n == 1) return n;
        for(auto x: st) nums[i] = x, i++;
        int ans = 1;
        int cur = 1;
        // for(auto i : nums) cout << i << " ";
        cout << endl;
        for(int i = 1; i < st.size(); i++){
            if(abs(nums[i] - nums[i-1]) < 2){
                cur++;
            }
            else cur = 1;
            // cout << cur << " ";
            ans = max(ans, cur);
        }
        return ans;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0, j = 0, ans = 0;
        multiset<int> st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
            while(*st.rbegin() - *st.begin() > limit){
                st.erase(st.find(nums[j++]));
            }
            ans = max(ans, (int)st.size());
        }
        return ans;
    }
};
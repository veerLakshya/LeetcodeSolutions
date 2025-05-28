class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n, -1);
        multiset<int> st(nums1.begin(), nums1.end());
        for(int i = 0; i < n; i++){
            auto it = st.upper_bound(nums2[i]);
            if(it == st.end()) continue;
            ans[i] = *it;
            st.erase(it);
        }
        for(auto &i: ans){
            if(i == -1){
                i = *st.begin();
                st.erase(st.begin());
            }
        }
        return ans;
    }
};
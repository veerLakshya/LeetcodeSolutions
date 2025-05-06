class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> a(100005,-1), ans;
        stack<int> st;
        st.push(nums2[n-1]);
        for(int i = n - 2; i >= 0; i--){
            while(st.size() && st.top() < nums2[i]) st.pop();
            if(st.size()) a[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for(auto i: nums1){
            ans.push_back(a[i]);
        }
        return ans;
    }
};
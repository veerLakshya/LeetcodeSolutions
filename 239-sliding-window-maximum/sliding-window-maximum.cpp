class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        multiset<int>st;
        // int prev=nums[0];
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
            if(i>=k){
                auto it = st.find(nums[i-k]);
                st.erase(it);
                // prev=nums[i-k+1];
            }
            if(i>=k-1){
                ans.push_back(*st.rbegin());
            }
        }
        return ans;
    }
};
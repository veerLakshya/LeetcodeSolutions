class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(), maxi = *max_element(nums.begin(), nums.end());
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(nums[i] == maxi){
                for(int j = i; j >= 0; j--){
                    st.push(nums[j]);
                }
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            while(st.size() && st.top() <= nums[i]){
                // cout << st.top() << " ";
                st.pop();
            }
            if(st.size()) ans[i] = st.top();
            else ans[i] = -1;
            st.push(nums[i]);
        }
        return ans;
    }
};
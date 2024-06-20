class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans = nums;
        multiset<int> st;
        sort(ans.begin(),ans.end());

        for(int i = nums.size()-1; i>=0;i--){
            st.insert(ans[i]);
            k--;
            if(!k)break;
        }
        ans.clear();
        for(auto i: nums){
            if(st.find(i)!=st.end()){
                ans.push_back(i);
            st.erase(st.find(i));
            }
        }
        return ans;
    }
};
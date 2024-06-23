class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0, j = 0, ans = 0;
        multiset<int> st;
        for(int i = 0; i < n; i++){
            if(st.size()>0){
                if(nums[i] < *st.begin()){
                    while(st.size()>0 && *st.rbegin() - nums[i] > limit){
                        st.erase(st.find(nums[j]));
                        j++;
                    }
                }
                else if(nums[i] > *st.rbegin()){
                    while(st.size()>0 && nums[i] - *st.begin() > limit){
                        st.erase(st.find(nums[j]));
                        j++;
                    }
                }
            }
            st.insert(nums[i]);
            ans = max(ans, (int)st.size());
        }
        return ans;
    }
};
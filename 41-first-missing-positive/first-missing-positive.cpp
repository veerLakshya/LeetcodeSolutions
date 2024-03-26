class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        for(int i=0;i<nums.size();i++)
        st.insert(nums[i]);
        for(int i=1;i<=nums.size();i++)
        {
            if(st.find(i)==st.end())return i;
        }
        return *st.rbegin()+1;
        
    }
};
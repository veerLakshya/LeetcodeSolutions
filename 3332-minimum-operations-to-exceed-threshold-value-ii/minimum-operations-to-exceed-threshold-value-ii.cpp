class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long ans = 0;
        multiset<long long> st;
        for(auto i: nums) st.insert(i);
        while(st.size() && * st.begin() < k){
            long long f = *st.begin();
            st.erase(st.find(f));
            long long s = *st.begin();
            st.erase(st.find(s));
            st.insert( 2*f + s);
            ans++;
        }
        return ans;
    }
};
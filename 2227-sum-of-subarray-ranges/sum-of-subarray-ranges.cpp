class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long n = nums.size();
        stack<long long> st;
        long long ans = 0;
        // ans = sum of all maxs - sum of all mins
        for(long long i = 0; i <= n; i++){
            // keep poping till i find a smaller element than current element
            while(st.size() && (i == n || nums[st.top()] >= nums[i])){
                // calc for cur element
                long long mid = st.top();
                st.pop();
                long long l = (st.size() ? st.top() : -1);
                long long r = i;
                ans -= (long long)nums[mid]*(r - mid)*(mid - l);
            }
            st.push(i);
        } 
        st.pop(); // to pop out the last extra n pushed to clear array
        for(int i = 0; i <= n; i++){
            // keep poping till i find a greater element than cur element so that cur is max of all these subarrays
            while(st.size() && (i == n || nums[st.top()] <= nums[i])){
                long long mid = st.top();
                st.pop();
                long long l = (st.size() ? st.top() : -1);
                long long r = i;
                ans += (long long)(nums[mid])*(r - mid)*(mid - l);
            }
            st.push(i);
        }
        return ans;
    }
};
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        int n = nums.size();
        multiset<double> st(nums.begin(), nums.begin() + k);
        auto mid = st.begin();
        for(int i = 0; i < k/2; i++){
            mid++;
        }
        for(int i = k; ; i++){
            if(k%2 == 1){ // subarray is odd
                ans.push_back(*mid);
            }
            else{
                ans.push_back((*mid + *prev(mid))/2.0);
            }
            if(i == n) return ans;
            st.insert(nums[i]);

            if(nums[i] < *mid) mid--;

            if(nums[i-k] <= *mid) mid++;
            
            st.erase(st.find(nums[i-k]));
        }

        return ans;
    }
};
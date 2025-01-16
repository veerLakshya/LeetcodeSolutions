class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, n = nums1.size() % 2, m = nums2.size() % 2;
        if(n) for(auto i: nums2) ans ^= i;
        if(m) for(auto i: nums1) ans ^= i;
        return ans;
    }
};
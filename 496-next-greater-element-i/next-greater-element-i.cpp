class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ng(1e4 + 2, -1);
        stack<int> s;
        for(int i = n - 1; i >= 0; i--){
            if(s.size() != 0){
                while(s.size() && s.top() < nums2[i]) s.pop();
                if(s.size()) ng[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(auto i: nums1) ans.push_back(ng[i]);
        return ans;
    }
};
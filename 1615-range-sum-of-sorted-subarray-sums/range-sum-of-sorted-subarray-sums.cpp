class Solution {
public:
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        multiset<int> st;
        for(int i = 0; i<n; i++){
            int l = i, sum=0;
            while(l!=n){
                sum += nums[l];
                sum %= mod;
                st.insert(sum % mod);
                l++;
            }
        }
        vector<int> ans;
        for(auto i: st) ans.push_back(i);
        left--,right--;
        int an = 0;
        for(int i = left; i<=right; i++){
            an+=ans[i];
            an%=mod;
        }
        return an;
    }
};
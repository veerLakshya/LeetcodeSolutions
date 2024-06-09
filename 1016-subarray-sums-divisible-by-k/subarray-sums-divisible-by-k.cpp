class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();
        vector<int> remainder(k,0);
        remainder[0] = 1;
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            sum = (sum%k) + k;
            ans += remainder[sum%k];
            remainder[(sum % k)]++;
        }
        return ans;        
    }
};
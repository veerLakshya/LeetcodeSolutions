class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int,int> mp;
        mp[0] = 1;
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            sum = (sum%k) + k;
            if(mp.find(sum % k) != mp.end()){
                ans += mp[sum % k];
            }
            // for(auto i: mp){
            //     cout<<i.first<<" "<<i.second<<endl;
            // }
            // cout<<ans<<" ";
            mp[(sum % k)]++;
        }
        return ans;        
    }
};
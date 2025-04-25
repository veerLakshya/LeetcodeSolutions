class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i: nums)mp[i]++;
        int n = nums.size(), x = mp.size();
        mp.clear();
        int ans = 0;
        for(int i = 0, j = 0; j < n; j++){
            mp[nums[j]]++;
            while(mp.size() == x){
                ans += n - j;
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};
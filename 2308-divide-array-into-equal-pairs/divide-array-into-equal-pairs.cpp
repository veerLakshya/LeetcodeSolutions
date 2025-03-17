class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> mp;
        for(auto i: nums) mp[i]++;
        for(auto i: mp) if((i.second) % 2) return 0;
        return 1;
        
    }
};
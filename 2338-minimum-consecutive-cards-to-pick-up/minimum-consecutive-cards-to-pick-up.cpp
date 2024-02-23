class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map <int,int> mp;
        int ans = INT_MAX;
        for(int i=0;i<cards.size();i++)
        {
            if(mp.find(cards[i])!=mp.end()){
                int count = i - mp[cards[i]];
                ans = min(ans,count);
            }
            mp[cards[i]]=i;
        }
        return ans==INT_MAX ? -1: ans+1;
        
    }
};
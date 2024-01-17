class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int,int> mp;
        for(auto i:arr)
            mp[i]++;
        
        unordered_set <int> v;
        for(auto i:mp)
        {
            if(v.find(i.second)!=v.end())
                return false;
            else 
                v.insert(i.second);
        }
        return true;
        
    }
};
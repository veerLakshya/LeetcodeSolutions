class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, n = fruits.size(), r = 0;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n; i++){
            while( r < n && ( mp.size() < 2 || mp.find(fruits[r])!=mp.end())){
                mp[fruits[r]]++;
                r++;
            }
            int cur = r - i;
            ans = max(ans, cur);
            mp[fruits[i]]--;
            if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
        }
        return ans;
    }
};
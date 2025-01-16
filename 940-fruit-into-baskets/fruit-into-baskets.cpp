class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, n = fruits.size(), r = 0;
        map<int,int> mp;
        for(int i = 0 ; i < n; i++){
            while( r < n && ( mp.size() < 2 || mp.find(fruits[r])!=mp.end())){
                mp[fruits[r]]++;
                r++;
            }
            int cur = 0;
            for(auto i: mp) cur += i.second;
            ans = max(ans, cur);
            mp[fruits[i]]--;
            if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
        }
        return ans;
    }
};
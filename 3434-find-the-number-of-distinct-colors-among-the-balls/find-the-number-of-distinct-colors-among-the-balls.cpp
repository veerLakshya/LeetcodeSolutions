class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int,int> mp, b;
        for(auto i: queries){
            int ball = i[0];
            int col = i[1];
            if(b.find(ball) != b.end()){
                mp[b[ball]]--;
                if(mp[b[ball]] == 0) mp.erase(b[ball]);
            }
            mp[col]++;
            b[ball] = col;
            ans.push_back(mp.size());
        }
        return ans;
    }
};
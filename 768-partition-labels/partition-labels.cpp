class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]] = i;
        }
        int cur = 0,maxright = 0;
        for(int i = 0; i < s.size(); i++){
            cur++;
            if(mp[s[i]] != i){
                maxright = max(maxright, mp[s[i]]);
            }
            else{
                if(i == maxright){
                    ans.push_back(cur);
                    cur = 0;
                    maxright = i+1;
                }
            }
        }
        return ans;
    }
};

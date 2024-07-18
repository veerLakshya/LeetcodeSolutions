class Solution {
public:
    int countGoodSubstrings(string s) {
        map <char,int> mp;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            if(i>=3){
                mp[s[i-3]]--;
                if(mp[s[i-3]]==0)mp.erase(s[i-3]);
            }
            if(i>=2){
                if(mp.size()==3)ans++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size() > s.size()) return ans;
        vector<int> fs1(26,0), fs2(26, 0);
        for(auto i: p) fs1[i-'a']++;

        int cur = 0, total = 0, k = p.size();

        for(auto i: fs1) total += (i > 0);

        for(int i = 0; i < s.size(); i++){
            if(i >= k){
                int p = s[i-k] - 'a';
                if(fs1[p]==fs2[p]) cur--;
                fs2[p]--;
            }
            int ch = s[i] - 'a';
            fs2[ch]++;
            if(fs1[ch] == fs2[ch]) cur++;
            if(cur == total) ans.push_back(i-k+1);
        }
        return ans;
    }
};
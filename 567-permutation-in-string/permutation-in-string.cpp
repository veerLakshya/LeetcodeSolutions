class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> fs1(26,0), fs2(26, 0);
        for(auto i: s1) fs1[i-'a']++;

        int cur = 0, total = 0, k = s1.size();

        for(auto i: fs1) total += (i > 0);

        for(int i = 0; i < s2.size(); i++){
            if(i >= k){
                int p = s2[i-k] - 'a';
                if(fs1[p]==fs2[p]) cur--;
                fs2[p]--;
            }
            int ch = s2[i] - 'a';
            fs2[ch]++;
            if(fs1[ch] == fs2[ch]) cur++;
            if(cur == total) return true;
        }
        return false;
    }
};
class Solution {
public:
    int minBitFlips(int start, int goal) {
        string r = std::bitset<32>(goal).to_string();
        string f = std::bitset<32>(start).to_string();
        int ans = 0;
        for (int i = 0 ; i < 32; i++){
            if(r[i]!=f[i])ans++;
        }
        return ans;
    }
};
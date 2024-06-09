class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans=0;
        vector<int> charIndex(128,-1);
        int left=0;
        for(int i = 0; i < n; i++){
            if(charIndex[s[i]]>=left){
                left = charIndex[s[i]]+1;
            }
            charIndex[s[i]] = i;
            ans = max(ans, i-left+1);
        }
        return ans;
    }
};
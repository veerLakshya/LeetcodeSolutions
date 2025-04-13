class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int half = n/2;
        string ans = "";
        int i = 0;
        while(ans.size() != half) ans += s[i], i++;
        sort(ans.begin(), ans.end());
        string rev = ans;
        reverse(rev.begin(), rev.end());
        if(n&1) ans += s[i];
        
        return ans+rev;
    }
};
class Solution {
public:
    int scoreOfParentheses(string s) {
        int cur = 0, ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') cur++;
            else cur--;
            // whenever we find a () we add 2^# of outerlayers to our answer
            if(s[i] == ')' && s[i-1] == '(') ans += 1 << cur;
        }
        return ans;
    }
};
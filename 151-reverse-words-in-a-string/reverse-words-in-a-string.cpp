class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string curr = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (!curr.empty()) {
                    reverse(curr.begin(), curr.end());
                    ans += curr;
                    ans.push_back(' ');
                    curr = "";
                }
            } else {
                curr += s[i];
            }
            s.pop_back();
        }
        if (!curr.empty()) {
            reverse(curr.begin(), curr.end());
            ans += curr;
        }
        if(ans.back()==' ')ans.pop_back();
        return ans;
    }
};
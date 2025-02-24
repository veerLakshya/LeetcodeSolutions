class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        auto h = [&](int i, int open, string s, auto self)->void{
            if(i >= 2*n){
                if(!open) ans.push_back(s);
                return;
            }
            self(i + 1, open + 1, s + '(', self);
            if(open) self(i + 1, open - 1, s + ')', self);
        };

        h(0, 0, "", h);

        return ans;
    }
};
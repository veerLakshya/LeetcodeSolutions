class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        function<void(int, string)> h = [&](int open, string cur)->void{
            if(cur.size() == 2*n){
                if(open == 0)ans.push_back(cur);
                return;
            }
            if(open) h(open - 1, cur + ')');
            h(open+1, cur + '(');
        };
        h(0, "");
        return ans;
    }
};
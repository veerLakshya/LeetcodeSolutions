class Solution {
public:
    vector<string> ans;
    int N;
    void helper(int index,int open,string st){
        if(index==N && open==0){
            ans.push_back(st);
            return;
        }
        if(index==N)return;
        helper(index+1,open+1,st+'(');
        if(open)
        helper(index+1,open-1,st+')');
    }
    vector<string> generateParenthesis(int n) {
        N=2*n;
        helper(0,0,"");
        return ans;
    }
};
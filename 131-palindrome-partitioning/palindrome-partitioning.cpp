class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;
    bool isPal(string& s, int left, int right){
        for(int i=left; i<=right;i++){
            if(s[i]!=s[right-(i-left)]) return false;
        }
        return true;
    }
    void backtrack(string& s, int ind, vector<string>& curr){
        if(ind == s.size()){
            ans.push_back(curr);
            return;
        }
        string temp = "";
        for(int i = ind; i < s.size(); i++){
            temp += s[i];
            if(isPal(s,ind,i)){
                curr.push_back(temp);
                backtrack(s,i+1,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(s, 0, curr);
        return ans;
    }
};
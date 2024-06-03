class Solution {
public:
    vector<string>pad{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;
    void helper(int index, string& digits, string current){
        if(index==digits.size()){
            ans.push_back(current);
            return;
        }
        string st = pad[digits[index] - '0'];
        for(auto i:st){
            current.push_back(i);
            helper(index+1,digits,current);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size())return ans;
        helper(0,digits,"");
        return ans;
    }
};
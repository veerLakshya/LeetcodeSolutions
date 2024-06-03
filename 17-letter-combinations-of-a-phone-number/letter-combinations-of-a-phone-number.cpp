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
            helper(index+1,digits,current+i);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size())return ans;
        helper(0,digits,"");
        return ans;
    }
};
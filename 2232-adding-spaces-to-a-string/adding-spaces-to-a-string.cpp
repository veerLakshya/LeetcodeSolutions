class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        sort(spaces.begin(),spaces.end());
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(j < spaces.size() && i == spaces[j]){
                ans += ' ';
                j++;
            }
            ans += s[i];
            if(j < spaces.size() && i == spaces[j] - 1){
                ans += ' ';
                j++;
            }
        }
        return ans;
    }
};
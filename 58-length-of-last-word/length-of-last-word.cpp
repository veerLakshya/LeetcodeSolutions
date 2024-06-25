class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        while(s.back() == ' '){
            s.pop_back();
        }
        int n = s.size();
        for(int i = n - 1; i >=0 ; i--){
            if(s[i]==' ')break;
            ans++;
        }
        return ans;
    }
};
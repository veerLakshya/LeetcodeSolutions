class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> st;
        for(int i=0;i<s.size();i++){
            st[s[i]]++;
        }
        int ans=0;
        for(auto i:st){
            ans+= (i.second/2)*2;
        }
        for(auto i:st){
            if((i.second)%2) return ans+1;
        }
        return ans;
    }
};
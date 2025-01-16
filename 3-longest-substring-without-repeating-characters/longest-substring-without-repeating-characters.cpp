class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int ans = 0, l = 0, n = s.size();
        for(int i = 0; i < n; i++){
            if(st.find(s[i])!=st.end()){
                while( st.find(s[i]) != st.end() ){
                    st.erase(s[l]);
                    l++;
                }
            }
            ans = max(ans, i - l + 1);
            st.insert(s[i]);
        }
        return ans;
    }
};
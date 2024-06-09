class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans=0;
        unordered_set<char> st;
        int left=0;

        for(int i=0;i<n;i++){
            if(st.find(s[i])==st.end()){
            }
            else{
                while(st.find(s[i])!=st.end()){
                    st.erase(s[left]);
                    left++;
                }
            }
                st.insert(s[i]);
                ans = max(ans,(int)st.size());
        }
        return ans;
    }
};
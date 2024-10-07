class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto i: s){
            if(st.empty()){
                st.push(i);
                continue;
            }
            if(i == 'B' && st.top() == 'A') st.pop();
            else if(i == 'D' && st.top() == 'C') st.pop();
            else st.push(i);
        }
        return st.size();
    }
};
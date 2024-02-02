class Solution {
public:
    bool matching(char a, char b){
        return(
            (a=='(' && b ==')')||
            (a=='{' && b =='}')||
            (a=='[' && b ==']')
            );
    }
    bool isValid(string s) {
        stack <int> st;
        for(char i:s){
            if(i=='{'||i=='('||i=='[')
            st.push(i);
            else{
                if(st.empty()) return false;
                if(matching(st.top(),i)==false) return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};
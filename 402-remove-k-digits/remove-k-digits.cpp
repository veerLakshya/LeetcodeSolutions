class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int i, j = 1, n = num.size();
        for(i = 0; i < num.size() && j <= k; i++){
            while(st.size() && j <= k && st.top() > num[i]) st.pop(), j++;
            st.push(num[i]);
        }
        while(i < n) st.push(num[i]), i++;
        while(j <= k && st.size()) st.pop(), j++;
        if(st.empty()) return "0";
        string ans ="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
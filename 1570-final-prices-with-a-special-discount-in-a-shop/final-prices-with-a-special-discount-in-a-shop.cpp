class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector <int> v;
        st.push(prices[n-1]);
        v.push_back(prices[n-1]);
        for(int i=n-2;i>=0;i--){
            while(st.empty()!=true && st.top()>prices[i]) st.pop();
            int p = (st.empty())? prices[i]: prices[i]-st.top();
            v.push_back(p);
            st.push(prices[i]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
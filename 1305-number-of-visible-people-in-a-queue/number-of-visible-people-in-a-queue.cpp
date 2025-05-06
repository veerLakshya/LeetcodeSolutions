class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n , 0);
        vector<int> st;
        int cnt = 0;
        for(int i = n - 1; i >= 0; i--){
            while(st.size() && heights[st.back()] <= heights[i]) st.pop_back(),cnt++;
            // for(auto i: st) cout << i << " ";
            ans[i] = cnt + (st.size() ? 1 : 0);
            cnt = 0;
            st.push_back(i);
            cout << endl;
        }
        return ans;
    }
};
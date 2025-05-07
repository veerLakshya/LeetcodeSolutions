class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> st;
        for(int i = 0; i <= n; i++){
            while(st.size() && (i == n || heights[st.top()] >= heights[i])){
                int ind = st.top();
                st.pop();
                int l = (st.size() ? st.top() : - 1);
                int r = i;
                ans = max(ans, heights[ind]*(r - l - 1));
            }
            st.push(i);
        }
        return ans;
    }
};

//check notes

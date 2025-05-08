class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<vector<int>> a(n, vector<int> (m, 0));
        for(int j = 0; j < m; j++) a[0][j] = (matrix[0][j] == '1');

        for(int j = 0; j < m; j++){
            for(int i = 1; i < n; i++){
                if(matrix[i][j] == '0') continue;
                else a[i][j] = 1 + a[i-1][j];
            }
        }
        // print(a);
        for(int i = 0; i < n; i++){
            stack<int> st;
            for(int j = 0; j <= m; j++){
                while(st.size() && (j == m || a[i][st.top()] >= a[i][j])){
                    int mid = st.top();
                    st.pop();
                    int l = (st.size() ? st.top() + 1 : 0);
                    int r = j;
                    int side = min((r - l), a[i][mid]);
                    // cout << r - l << " " << a[i][mid] << endl;;
                    // cout << mid << " smaller on:"<< l << endl;
                    ans = max(ans, side*side);
                }
                st.push(j);
            }
            // cout << endl;
        }
        return ans;
    }
};
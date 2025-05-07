class Solution {
public:
    void print(auto& a) {
        for (auto i : a) {
            for (auto j : i)
                cout << j << " ";
            cout << endl;
        }
        cout << endl;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        auto a = vector<vector<int>>(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = (matrix[i][j] == '1');
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (a[i][j])
                    a[i][j] += a[i - 1][j];
            }
        }
        // considering a max rectangle formed till this level
        for (int i = 0; i < n; i++) {
            stack<int> st;
            for (int j = 0; j <= m; j++) {
                while (st.size() && (j == m || a[i][st.top()] >= a[i][j])) {
                    int y = st.top();
                    st.pop();
                    int h = a[i][y];
                    int w = (st.size() ? j - st.top() - 1: j);
                    ans = max(ans, h * w);
                }
                st.push(j);
            }
        }
        // print(a);
        return ans;
    }
};
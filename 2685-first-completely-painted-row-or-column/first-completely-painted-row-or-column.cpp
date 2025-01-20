class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<int> r(rows), c(cols);
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int value = mat[i][j];
                pos[value] = {i, j};
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            auto [row, col] = pos[num];
            r[row]++;
            c[col]++;
            if (r[row] == cols || c[col] == rows) return i;
        }
        return -1; 
    }
};
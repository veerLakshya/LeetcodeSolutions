class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt = 1;
        int res = 0;
        for (int i = 1; i < colors.size() + k - 1; i++) {
            int j = i % colors.size();
            if (colors[j] != colors[(j - 1 + colors.size()) % colors.size()]) cnt++;
            else cnt = 1;
            if (cnt >= k) res++;
        }
        return res;
    }
};
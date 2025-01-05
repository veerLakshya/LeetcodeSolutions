class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> pre(s.size(), 0);
        for (auto i : shifts) {
            int l = i[0], r = i[1];
            if (i[2] == 1) {
                pre[l]++;
                if(r + 1 < n) pre[r + 1]--;
            } else {
                pre[l]--;
                if(r + 1 < n) pre[r + 1]++;
            }
        }
        string ans(n,' ');
        int cur = 0;
        for(int i = 0; i < n; i++){
            cur = (cur + pre[i]) % 26;
            if(cur < 0) cur += 26;
            ans[i] = 'a' + (s[i] - 'a' + cur) % 26;
        }
        return ans;
    }
};
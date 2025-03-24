class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans = 0;
        int last = 0;
        for(int i = 0; i < meetings.size(); i++){
            vector<int> temp = meetings[i];
            int l = temp[0], r = temp[1];
            if(last < l) ans += (l - last - 1);
            last = max(last, r);
            // cout << ans << " ";
        }
        ans += (days - last);
        return ans;
    }
};
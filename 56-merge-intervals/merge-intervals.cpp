class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(*intervals.begin());
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= ans.back()[1]){
                vector<int> last = ans.back();
                ans.pop_back();
                last[1] = max(last[1], intervals[i][1]);
                ans.push_back(last);
            }
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};
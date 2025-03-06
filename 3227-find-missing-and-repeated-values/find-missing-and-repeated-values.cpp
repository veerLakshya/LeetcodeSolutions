class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid.size();
        vector<int> freq(n*n + 1, 0);
        for(auto i: grid){
            for(auto j: i){
                if(!freq[j]) freq[j]++;
                else ans.push_back(j);
            }
        }
        for(int i = 1; i <= n*n; i++) if(!freq[i]){
            ans.push_back(i);
            break;
        }
        return ans;
    }
};
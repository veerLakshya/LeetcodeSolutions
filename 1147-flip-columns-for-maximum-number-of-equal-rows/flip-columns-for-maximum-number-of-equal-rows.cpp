class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int ans = 0;
        map<string,int> mp;

        for(int i = 0; i < matrix.size(); i++){
            string st,ts;
            for(int j = 0; j < matrix[0].size(); j++){
                st += (matrix[i][j] == 1 ? "1" : "0");
                ts += (matrix[i][j] == 1 ? "0" : "1");
                // cout<<matrix[i][j];
            }
            // cout<<st<<" "<<ts<<endl;
            mp[st]++;
            mp[ts]++;
            // cout<<endl;
        }
        for(auto i:mp){
            ans = max(ans, i.second);
        }
        return ans;
    }
};
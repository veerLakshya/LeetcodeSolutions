class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> ans, pre(words.size() + 1, 0);
        int n = words.size();
        for (int i = 0; i < n; i++) {
            char c1 = words[i][0];
            char c2 = words[i][words[i].size() - 1];
            if ((c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' ||
                 c1 == 'u') &&
                (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u')){
                    pre[i+1]++;
                }
        }
        for(int i = 1; i <= n; i++ ) pre[i] += pre[i-1];
        // for(auto i: pre) cout << i << " ";
        // cout<<endl;
        for(auto q : queries){
            int i = q[0], j = q[1];
            // cout<<i<<" "<<j<<endl;
            ans.push_back(pre[j+1]-pre[i]);
        }
        return ans;
    }
};
class Solution {
public:
    set<string> ans;
    int n;
    void h(string cur, string s,vector<int>& used){
        for(int i = 0; i < n; i++){
            if(!used[i]){
                used[i] = 1;
                ans.insert(cur + s[i]);
                h(cur + s[i], s, used);
                used[i] = 0;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        vector<int> used(n, 0);
        h("", tiles, used);
        return ans.size();
    }
};
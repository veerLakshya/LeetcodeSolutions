class Solution {
public:
    int n;
    set<string>s;
    void helper(vector<int> &vis, string& curr, string &tiles){
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                s.insert(curr+tiles[i]);
                vis[i]=1;
                curr+=tiles[i];
                helper(vis,curr,tiles);
                curr.pop_back();
                vis[i]=0;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        n=tiles.size();
        vector<int> vis(n,0);
        string curr="";
        helper(vis, curr, tiles);
        return s.size();
    }
};
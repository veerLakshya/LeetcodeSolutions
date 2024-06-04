class Solution {
public:
    int n;
    vector<string> ans;
    int helper(int size, string tiles,vector<int>& freq){
        int res=0;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                res++;
                freq[i]--;
                res+=helper(size+res,tiles,freq);
                freq[i]++;
            }
        }
        return res;
    }
    int numTilePossibilities(string tiles) {
        n=tiles.size();
        vector<int> freq(26,0);
        for(auto i:tiles){
            freq[i-'A']++;
        }
        for(auto i:freq)cout<<i<<" ";
        return helper(0,tiles,freq);
        // return ans.size();
    }
};
class Solution {
public:
    int n;
    int helper(vector<int>& freq){
        int res = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                res++;
                freq[i]--;
                res += helper(freq);
                freq[i]++;
            }
        }
        return res;
    }
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        vector<int> freq(26,0);
        for(auto i : tiles) freq[i - 'A']++;
        return helper(freq);
    }
};
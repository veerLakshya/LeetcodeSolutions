class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = 1e9;
        for(int x = 1; x <= 6; x++){
            int cur = 0, poss = 1, low = 0, high = 0;
            for(int i = 0; i < n; i++){
                if(tops[i] != x && bottoms[i]!= x) {
                    poss = 0;
                    break;
                }
                else{
                    if(tops[i] == x) high++;
                    if(bottoms[i] == x) low++;
                }
            }
            if(poss){
                ans = min({ans, n-max(low,high)});
            }
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};
class Solution {
public:
    set<array<int,3>> st;
    int dp[50002][4][4][4];
    int mod = 1e9 + 7;
    int h(int ind, int c1, int c2, int c3){
        if(ind <= 0) return 1;
        if(dp[ind][c1][c2][c3] != -1) return dp[ind][c1][c2][c3];
        int ways = 0;
        for(auto i: st){
            if(i[0] != c1 && i[1] != c2 && i[2] != c3) ways = (ways + h(ind - 1, i[0], i[1], i[2])) % mod;
        }
        return dp[ind][c1][c2][c3] = ways % mod;
    }
    int numOfWays(int n) {
        memset(dp, -1, sizeof dp);
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                if(i == j) continue;
                for(int k = 1; k <= 3; k++){
                    if(j == k) continue;
                    st.insert({i,j,k});
                }
            }
        }
        // cout << st.size();
        return h(n, 0, 0, 0);
    }
};
class Solution {
public:
    int n;
    vector<int> a;
    long long dp[1001][502][3];
    long long h(int ind, int k, int buy){
        if(k == 0) return 0;
        if(ind == n) {
            if(buy == 2) return -1e9;
            else return 0;
        }

        if(dp[ind][k][buy] != -1) return dp[ind][k][buy];

        if(!buy){ // 0 - i dont have anything so buy, pass or short sell
            long long op1 = -a[ind] + h(ind + 1, k, 1);
            long long op2 = a[ind] + h(ind + 1, k, 2);
            long long op3 = h(ind + 1, k, 0);
            return dp[ind][k][buy] = max({op1, op2, op3});
        }
        else if(buy == 1){ // 1 - i have a stock so either sell or pass
            long long op1 = a[ind] + h(ind + 1, k - 1, 0);
            long long op2 = h(ind + 1, k, buy);
            return dp[ind][k][buy] = max(op1, op2);
        }
        else if (buy == 2){ // 2 - i sold a stock so i need to buy or pass
            long long op1 = -a[ind] + h(ind + 1, k - 1, 0);
            long long op2 = h(ind + 1, k, buy);
            return dp[ind][k][buy] = max(op1, op2);
        }
        return 0;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp, -1, sizeof dp);
        n = prices.size();
        a = prices;
        return h(0,k,0);
    }
};
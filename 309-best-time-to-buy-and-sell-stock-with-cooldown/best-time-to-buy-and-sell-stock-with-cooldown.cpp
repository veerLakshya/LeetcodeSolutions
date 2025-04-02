class Solution {
public:
    int dp[5001][2][2];
    int h(int i, int own, int cool, vector<int>& a){
        if(i == a.size()) return 0;
        if(dp[i][own][cool] != -1) return dp[i][own][cool];
        if(own){
            // if i already have a stock
            int op1 = a[i] + h(i+1, 0, 1, a);
            int op2 = h(i+1, 1, 0, a);
            return dp[i][own][cool] = max(op1, op2);
        }
        else{
            if(cool) return dp[i][own][cool] = h(i+1, 0, 0, a);
            else{
                int op1 = -a[i] + h(i+1, 1, 0, a);
                int op2 = h(i+1, 0, 0, a);
                return dp[i][own][cool] = max(op1, op2);
            }
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return h(0, 0, 0, prices);
    }
};

/*
if i have a stock (buy == 1)
    op1 - i can sell and get cooldown
    op2 - i pass and no cooldown
if i dont have a stock (buy == 0)
    if(cooldown)
        op - i cant buy and remove cooldown
    else
        op1 - i buy and still no cooldown
        op2 - i pass and no cooldown

*/
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int drinkable = numBottles;
        int empty = 0;
        while(drinkable>0){
            ans += drinkable;
            empty += drinkable;
            drinkable = empty/numExchange;
            empty -= numExchange*drinkable;
        }
        return ans;
    }
};
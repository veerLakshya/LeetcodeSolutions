class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto x: nums){
            vector<int> div;
            int cur = 0;
            for(int i = 1; i <= sqrt(x); i++){
                if(x%i == 0){
                    div.push_back(i);
                    cur+=i;
                    if(x/i != i){
                        div.push_back(x/i);
                        cur += x/i;
                    }
                }
            }
            if(div.size() == 4) ans += cur;
        }
        return ans;
    }
};
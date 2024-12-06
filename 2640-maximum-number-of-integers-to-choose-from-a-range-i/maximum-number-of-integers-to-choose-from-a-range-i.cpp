class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> ban(n+1, 0);
        for(auto i: banned) if(i <= n) ban[i]++;
        int cur = 0, ans = 0;
        for(int i = 1; i <= n; i++) if(!ban[i]){
            if(cur + i <= maxSum){
                cur += i;
                ans++; 
            }
            else break;
        }
        return ans;
    }
};
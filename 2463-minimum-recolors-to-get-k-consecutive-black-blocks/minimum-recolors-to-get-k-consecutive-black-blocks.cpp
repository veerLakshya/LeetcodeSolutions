class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = n, cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += (blocks[i] == 'B');
            if(i >= k) cnt -= (blocks[i-k] == 'B');
            if(i+1 >= k) ans = min(ans, k-cnt);
        }
        return ans;  
    }
};
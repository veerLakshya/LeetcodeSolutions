class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans=0;
        sort(piles.rbegin(),piles.rend());
        for(auto i:piles)cout<<i<<" ";
        int i=1;
        int cnt=0;
        while(cnt<piles.size()/3){
            ans+=piles[i];
            i+=2;
            cnt++;
        }
        return ans;
    }
};
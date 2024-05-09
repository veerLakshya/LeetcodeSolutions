class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        sort(happiness.rbegin(),happiness.rend());
        // reverse(happiness.begin(),happiness.end());
        for(int i=0;i<k;i++){
            if(happiness[i]-i>0)
            ans+=(happiness[i]-i);

        }
        return ans;
    }
};
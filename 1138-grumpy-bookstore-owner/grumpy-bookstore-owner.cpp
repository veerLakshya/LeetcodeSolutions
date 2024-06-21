class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int k = minutes;
        int ans = 0;
        int maxi = 0;
        int unsatisfied=0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==1)unsatisfied+=customers[i];
            else ans+=customers[i];
            if(i>=k && grumpy[i-k]==1)unsatisfied-=customers[i-k];
            if(i>=k-1)maxi = max(maxi,unsatisfied);
        }
        cout<< ans<<" "<<maxi;
        return ans+maxi;
    }
};
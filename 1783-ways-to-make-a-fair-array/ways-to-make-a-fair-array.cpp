class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        vector<int> psE(n, 0), psO(n, 0);
        psE[0] = nums[0];

        for(int i = 1; i < n; i++){
            if(i % 2 == 0 ) psE[i] = psE[i-1] + nums[i], psO[i] = psO[i-1];
            else psO[i] = psO[i-1] + nums[i] , psE[i] = psE[i-1];
        }
        // for(auto i: psE) cout << i << " ";
        // cout << endl;
        // for(auto i: psO) cout << i << " ";

        for(int i = 0; i < n; i++){
                int oddL = i - 1 >= 0 ? psO[i - 1] : 0;
                int oddR = psE[n-1] - psE[i];
                int evenL = i - 1 >= 0 ? psE[i - 1] : 0;
                int evenR = psO[n - 1] - psO[i];
                // cout << oddL + oddR <<" "<< evenL + evenR<<endl;
                if(oddL + oddR == evenL + evenR)ans++;
    
        }
        return ans;
    }
};
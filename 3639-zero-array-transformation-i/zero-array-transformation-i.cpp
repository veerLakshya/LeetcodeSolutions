class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int op[100069]{0};
        for(auto i: queries){
            int l = i[0];
            int r = i[1];
            r++;
            op[l] += 1;
            op[r] -= 1;
        }
        for(int i = 0; i < nums.size(); i++){
            op[i] += (i > 0 ? op[i-1] : 0);
            if(op[i] < nums[i]) return false;
            // cout << op[i] << " "<<nums[i] << endl;
        }  
        return 1;
    }
};
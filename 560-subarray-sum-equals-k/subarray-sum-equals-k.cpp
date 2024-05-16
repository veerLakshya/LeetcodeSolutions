class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector <int> pre(n+1,0);
        for(int i=0;i<n;i++)
            pre[i+1] = pre[i]+ nums[i];
        unordered_map <int,int> mp;
        int ans =0;
        for(int i=0;i<=n;i++){
            // int pre[i]-pre[?]=k
            if(mp.contains(pre[i]-k))ans+=mp[pre[i]-k];
            mp[pre[i]]++;
        }
        return ans;
        
    }
};

// 1 2 3 4 6 k=4
// 0 1 3 6 10 16
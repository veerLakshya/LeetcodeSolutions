class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    if(n==2){
        if(nums[0]==1) return {1,2};
        else return {2,1};
    }
    sort(nums.begin(),nums.end());
    int repeat=nums[0];
    int miss=1;
    int sum = n*(n+1)/2;
    for(int i=1;i<n;i++)
    {
        if(nums[i]==nums[i-1]) repeat = nums[i];
        sum-=nums[i];
    }
    miss = sum + repeat - nums[0];
    cout<<repeat<<" "<< miss<<endl;

    return {repeat,miss};
    }
};
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        // int low=0;
        // int high=nums.size()-1;
        // while(low<=high){
        //     int mid=(low+high)/2;
        //     if(nums[mid]<0)
        //     low=mid+1;
        //     else
        //     high=mid-1;
        // }
        // int neg=low<0?0:low+1;
        //  high=nums.size()-1;
        // while(low<=high){
        //     int mid=(low+high)/2;
        //     if(nums[mid]==0)
        //     low=mid-1;
        //     else
        //     high=mid+1;
        // }
        // return max(neg,low);
        int cntn=0;
        int cntp=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0)cntn++;
            else if(nums[i]>0)cntp++;
        }
        return max(cntn,cntp);
        
    }
};
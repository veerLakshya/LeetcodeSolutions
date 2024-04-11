class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int n=nums1.size();
        int m=nums2.size();
        vector<double> v;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else {
               v.push_back(nums2[j]);
               j++;
            }
        }
        for(int x=i;x<n;x++){
            v.push_back(nums1[x]);
        }
        for(int x=j;x<m;x++){
            v.push_back(nums2[x]);
        }
        double ans;
        for(auto i: v)cout<<i<<" ";
        if((n+m)%2)ans= v[(n+m)/2];
        else ans= (v[(n+m)/2]+v[(n+m)/2 -1])/2;
        return ans;
    }
};
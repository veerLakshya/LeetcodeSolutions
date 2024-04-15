class Solution {
public:
    bool check(int x,vector<int> arr,int m){
        int count=1;
        int pre=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-pre>=x){
                count++;
                pre=arr[i];
            }
            if(count>=m)return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low =0;
        int  high=INT_MAX;
        int ans;
        while(low<=high){
            int mid=(high+low)/2;
            if(check(mid,position,m)){
                ans=mid;
                low=mid+1;
            }
            else 
                high=mid-1;

        }
        return ans;
    }
};
class Solution {
public:
    bool check(int x,vector<int>v,int n){
        int cnt=0;
        for(auto i:v){
            if(i%x) cnt+= i/x +1;
            else cnt+=i/x;
        }
        return cnt<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,quantities,n)){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};
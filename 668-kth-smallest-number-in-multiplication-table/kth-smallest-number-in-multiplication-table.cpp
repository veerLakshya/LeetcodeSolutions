class Solution {
public:
    bool check(int x,int m,  int n, int k){
        int el_b_x = 0;
        for(int i=1;i<=m;i++){
            int p;
            if(x%i!=0)p=x/i;
            else p= (x/i) -1;
            el_b_x+= min(n,p);
        }
        return el_b_x<=k-1;
    }
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = n*m;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,m,n,k)){
                low = mid+1;
                ans = mid;
            }else{
                high = mid-1;
            }
        }
        return ans;
        
    }
};
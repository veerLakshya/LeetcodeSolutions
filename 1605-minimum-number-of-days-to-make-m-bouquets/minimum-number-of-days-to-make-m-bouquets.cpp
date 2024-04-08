class Solution {
public:
    bool check(long long x, vector <int> arr, long long m, long long k){
        long long cnt=0;
        long long  total=0;
        for(long long i=0;i<arr.size();i++){
            if(x>=arr[i]){
                // cout<<i;
                cnt++;
                if(cnt==k){
                    total++;
                    cnt=0;
                }
            }
            else cnt=0;
        }
        return total>=m;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long low = *min_element(bloomDay.begin(),bloomDay.end());
        long long high = *max_element(bloomDay.begin(),bloomDay.end());
        long long ans = -1;
        while(low<=high){
            long long mid = (low+high)/2;
            if(check(mid,bloomDay,m,k)){
                ans = mid;
                high = mid-1;
                cout<<"*";
            }
            else{
                cout<<"~";
                low = mid+1;
            }
        }
        return ans==-1?-1:ans;
    }
};
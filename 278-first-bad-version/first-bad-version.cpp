// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n, ans = 0;
        while(i <= j){
            int mid = i - (i - j) / 2;
            if(isBadVersion(mid)){
                ans = mid;
                j = mid - 1;
            }
            else i = mid + 1;
        }
        return ans;
    }
};
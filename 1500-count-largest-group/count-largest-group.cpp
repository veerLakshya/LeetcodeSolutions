class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> freq(n+1, 0);
        for(int i = 1; i <= n; i++){
            int x = i;
            int sum = 0;
            while(x > 0){
                sum += x%10;
                x = x/10;
            }
            freq[sum]++;
        }
        int maxi = *max_element(freq.begin(), freq.end());
        return count(freq.begin(), freq.end(), maxi);
    }
};
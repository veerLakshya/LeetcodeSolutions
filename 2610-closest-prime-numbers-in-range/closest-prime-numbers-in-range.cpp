class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> isPrime(right+1, 1);
        vector<int> primes;
        for(int i = 2; i <= right; i++){
            if(isPrime[i]){
                primes.push_back(i);
                for(int j = 2; i * j <= right; j++){
                    isPrime[i*j] = 0;
                }
            }
        }
        // for(int i = 1; i <= right; i++){
        //     cout << i <<" :"<<isPrime[i]<<endl;
        // }
        vector<int> ans(2,-1);
        int mini = INT_MAX;
        for(int i = 1; i < primes.size(); i++){
            if((primes[i-1] >= left) && primes[i]-primes[i-1] < mini){
                mini = primes[i] - primes[i-1];
                ans[0] = primes[i-1];
                ans[1] = primes[i];
            }
        }
        return ans;
    }
};
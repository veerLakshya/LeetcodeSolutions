class Solution {
public:
    int sieve(long long n) {

        vector<bool> isprime(n,true);
        // isprime[0] =false;
        // isprime[1] = false;
        for (int i = 2; i < n; i++) {
            if (isprime[i] && (long)i * i < n) {
                for (int j = i * i; j < n; j += i)
                    isprime[j] = false;
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (isprime[i])
                cnt++;
        }
        return cnt;
    }
    int countPrimes(int n) { return sieve(n); }
};
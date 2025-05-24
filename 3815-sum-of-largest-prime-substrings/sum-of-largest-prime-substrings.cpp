class Solution {
public:
    bool isPrime(long long n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (long long i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        set<long long> primes;
        for (int i = 0; i < n; i++) {
            long long cur = 0;
            for (int j = i; j < n; j++) {
                cur *= 10;
                cur += (s[j] - '0');
                if (isPrime(cur)){
                    primes.insert(cur);
                }
            }
        }
        cout << endl;
        long long ans = 0;
        vector<int> a;
        while(primes.size() > 3) primes.erase(primes.find(*primes.begin()));
        for(auto i: primes) ans += i;
        return ans;
    }
};
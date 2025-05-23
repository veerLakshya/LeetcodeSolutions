class Solution {
public:
    int even = 5;
    int odd = 4;
    int mod = 1e9 + 7;
    long long binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long ans = binpow(even, (n+1)/2, mod)*binpow(odd, n/2, mod) % mod;
        return ans;
    }
};
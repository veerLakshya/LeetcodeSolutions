class Solution {
public:

    int kthFactor(int n, int k) {
        vector<long long> factors;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                factors.push_back(i);
                if(n/i!=i)factors.push_back(n/i);
            }
        }
        sort(factors.begin(),factors.end());
        return factors.size()>=k?factors[k-1]:-1;
    }
};
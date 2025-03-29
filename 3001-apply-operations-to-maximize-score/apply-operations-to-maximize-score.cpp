class Solution {
public:
    const int MOD = 1e9 + 7;

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];

            for (int factor = 2; factor <= sqrt(num); factor++) {
                if (num % factor == 0) {
                    s[i]++;

                    while (num % factor == 0)
                        num /= factor;
                }
            }
            if (num >= 2)
                s[i]++;
        }

        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);

        // Stack to store indices for monotonic decreasing prime score
        stack<int> st;

        // Calculate the next and previous dominant indices for each number
        for (int i = 0; i < n; i++) {
            // While the stack is not empty and the current prime score is
            // greater than the stack's top
            while (!st.empty() && s[st.top()] < s[i]) {
                int topIndex = st.top();
                st.pop();

                // Set the next dominant element for the popped i
                nextDominant[topIndex] = i;
            }

            // If the stack is not empty, set the previous dominant element for
            // the current i
            if (!st.empty())
                prevDominant[i] = st.top();

            st.push(i);
        }

        // Calculate the number of subarrays in which each element is dominant
        vector<long long> numOfSubarrays(n);
        for (int i = 0; i < n; i++) {
            numOfSubarrays[i] = (long long)(nextDominant[i] - i) *
                                    (i - prevDominant[i]);
        }

        priority_queue<pair<long, long>> q;

        for (int i = 0; i < n; i++)
            q.push({nums[i], i});

        long long score = 1;

        while (k > 0) {
            pair<long,long> cur = q.top();
            q.pop();
            long long num = cur.first, i = cur.second;

            // Calculate the number of operations to apply on the current
            // element
            long long operations = min((long long)k, numOfSubarrays[i]);

            // Update the score by raising the element to the power of
            // operations
            score = (score * power(num, operations)) % MOD;

            k -= operations;
        }

        return score;
    }

private:
    long long power(long long base, long long exponent) {
        long long res = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                res = ((res * base) % MOD);
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }
        return res;
    }
};
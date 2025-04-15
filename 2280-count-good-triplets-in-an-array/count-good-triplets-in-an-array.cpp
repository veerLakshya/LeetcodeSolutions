class Solution {
public:
    // Binary Indexed Tree (Fenwick Tree) to efficiently perform prefix sum queries and updates
    class BIT {
    public:
        vector<int> ar;
        int n;
        // Constructor to initialize the BIT with size n
        BIT(int _n) {
            n = _n;
            ar.resize(n, 0);
        }
        // Query the sum of elements in the range [l, r]
        int query(int l, int r) {
            if (r < l)
                return 0;
            return sum(r) - sum(l - 1);
        }
        // Compute prefix sum from index 0 to pos
        int sum(int pos) {
            int ans = 0;
            for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
                ans += ar[i];
            return ans;
        }
        // Increment the count at index 'pos'
        void update(int pos) {
            for (int i = pos; i < n; i |= i + 1)
                ar[i]++;
        }
    };

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            a[nums1[i]] = i;
            b[nums2[i]] = i;
        }

        long long ans = 0;
        BIT bit(n); // Binary Indexed Tree to keep track of visited indices in nums2

        // Iterate over each element in nums1 and consider it as the 'middle' of the triplet
        for (int i = 0; i < n; i++) {
            int indexInNums2 = b[nums1[i]];

            // Update BIT to mark current element from nums1 as visited in nums2
            bit.update(indexInNums2);

            // Count of elements that appeared before indexInNums2 in nums2
            // and also appeared before i in nums1 (common elements)
            int commonBefore = bit.query(0, indexInNums2 - 1);

            // Count of elements after indexInNums2 in nums2
            // that haven't been visited yet (i.e., not yet considered in nums1)
            int totalRight = (n - 1 - indexInNums2);
            int visitedRight = bit.query(indexInNums2 + 1, n - 1);
            int commonAfter = totalRight - visitedRight;

            // For current nums1[i] as the middle of the triplet,
            // the number of good triplets = commonBefore * commonAfter
            ans += 1LL * commonBefore * commonAfter;
        }

        return ans;
    }
};
// Brute Force - 
// M1 - generate all subsequences of size 3 of nums1 and all of nums2 and find the number of common subsequences
// M2 - for every middle element find number of common elements on left and right of that element in both arrays
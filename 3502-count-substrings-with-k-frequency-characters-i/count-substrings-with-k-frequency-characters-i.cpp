class Solution {
public:
    // Brute force - calculate all substrings and calc freq then increase count
    // O(n^3) can try by generation subsets while keeping track of freq of each
    // element in current subset

    int numberOfSubstrings(string s, int k) {
        int ans = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                bool f = 0;
                for (int l = 0; l < 26 ; l++){
                    if (freq[l] >= k) {
                        f = 1;
                        break;
                    }
                }
                if(f)ans++;
            }
        }
        return ans;
    }
    // O(26*n*n)
};
// O(n) - sliding window
// O(nlogn) - binary search plus prefix sum
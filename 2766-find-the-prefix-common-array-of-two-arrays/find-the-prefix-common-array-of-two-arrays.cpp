class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int cur = 0, n = A.size();
        vector<int> ans, freq(n+1, 0);
        for(int i = 0; i < n; i++){
            freq[A[i]]++;
            freq[B[i]]++;
            if(freq[A[i]] > 1) cur++;
            if(A[i] != B[i] && freq[B[i]] > 1) cur++;
            ans.push_back(cur);
        }
        return ans;
    }
};
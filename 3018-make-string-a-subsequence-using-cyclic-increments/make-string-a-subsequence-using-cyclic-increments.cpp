class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(str1[i]==str2[j]){
                i++; j++;
                continue;
            }
            while(i < n && ((str1[i] + 1 - 'a')%26 != str2[j] - 'a') && str1[i] != str2[j]) i++;
            str1[i] = str2[j];

        }
        if(j == m) return true;
        else return false;
    }
};
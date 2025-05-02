class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = dominoes;
        int n = s.size();
        int x = -1;
        for(int i = 0; i <= n; i++){
            if(i != n && s[i] == 'L'){
                if(x == -1){
                    for(int j = i - 1; j >= 0 && s[j] == '.'; j--) s[j] = 'L';
                }
                else{
                    for(int r = i - 1, l = x + 1; l < r; l++, r--){
                        s[l] = 'R';
                        s[r] = 'L';
                    }
                    x = -1;
                }
            }
            else if(i == n || s[i] == 'R'){
                if(x != -1) {
                    for(int j = x + 1; j <= i; j++) s[j] = 'R';
                }
                x = i;
            }
        }
        return s;
    }
};
class Solution {
public:
    int minMaxDifference(int num) {
        string mini = to_string(num);
        string maxi = mini;
        int n = mini.size();
        for(int i = 0; i < n; i++){
            if(maxi[i] != '9'){
                for(int j = i + 1; j < n; j++){
                    if(maxi[j] == maxi[i]) maxi[j] = '9';
                }
                maxi[i] = '9';
                break;
            }
        }
        char rep = mini[0];
        replace(mini.begin(), mini.end(), rep, '0');
        return stoi(maxi) - stoi(mini);
    }
};
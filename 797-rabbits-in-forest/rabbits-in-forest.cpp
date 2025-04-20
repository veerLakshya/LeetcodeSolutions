class Solution {
public:
    int freq[1069]{0};
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        for(auto i: answers){
            if(!i) ans++;
            else{
                if(!freq[i]){
                    ans += i + 1;
                    freq[i] = i;
                }
                else freq[i]--;
            }
        }
        return ans;
    }
};
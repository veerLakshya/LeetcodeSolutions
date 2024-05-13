class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digits;
        int n=num;
        int x=0;
        while(n){
            digits.push_back(n%10);
            n=n/10;
        }
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]==6){
                digits[i]=9;
                break;
            }
        }
        for(int i=digits.size()-1;i>=0;i--){
            x*=10;
            x+=digits[i];
        }
        return x;
    }
};
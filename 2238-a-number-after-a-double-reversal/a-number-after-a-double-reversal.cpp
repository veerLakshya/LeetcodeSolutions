class Solution {
public:
    int reverseDigits(int num) 
    { 
        int rev_num = 0; 
        while (num > 0) { 
            rev_num = rev_num * 10 + num % 10; 
            num = num / 10; 
        } 
        return rev_num; 
    } 
    bool isSameAfterReversals(int num) {
        // return reverseDigits(num)==num;
        if(num ==0)return 1;
        return num%10?1:0;
    }
};
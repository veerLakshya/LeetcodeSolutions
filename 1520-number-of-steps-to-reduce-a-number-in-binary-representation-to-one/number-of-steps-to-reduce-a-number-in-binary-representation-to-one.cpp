class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        int carry=0;
        for(int i=s.size()-1;i>0;i--){
            if((s[i]-'0')+carry == 1){
                ans+=2;
                carry=1;
            }else{
                ans++;
            }
        }
        return ans+carry;
    }
};
// 13 1101
// 14 1110
// 07 0111
// 08 1000
// 04 0100
// 02 0010
// 01 0001

// 1111011110000011100000110001011011110010111001010111110001
// 1111011110000011100000110001011011110010111001010111110010
// 0111101111000001110000011000101101111001011100101011111001
// 0111101111000001110000011000101101111001011100101011111010
// 0011110111100000111000001100010110111100101110010101111101
// 0011110111100000111000001100010110111100101110010101111110
// 0001111011110000011100000110001011011110010111001010111111
// 0001111011110000011100000110001011011110010111001011000000


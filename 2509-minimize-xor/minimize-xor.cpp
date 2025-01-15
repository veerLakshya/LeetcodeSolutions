class Solution {
public:
    int minimizeXor(int num1, int num2) {
        string binary1 = std::bitset<32>(num1).to_string();
        int alreadyOnBits = __builtin_popcount(num1);
        int bits = __builtin_popcount(num2);
        // cout << binary1 << " " << bits << endl;
        int ans = 0;

        if(bits == alreadyOnBits) return num1;

        if(bits > alreadyOnBits){
            int dif = bits - alreadyOnBits, n = binary1.size();
            for(int i = n-1; i >= 0; i--){
                if(dif > 0 && binary1[i] == '0'){
                    binary1[i] = '1';
                    dif--;
                }
            }
            cout<<"=";
        }
        else{
            int dif = alreadyOnBits - bits, n = binary1.size();
            for(int i = n-1; i >= 0; i--){
                if(dif > 0 && binary1[i] == '1'){
                    binary1[i] = '0';
                    dif--;
                }
            }
        }
        // cout << binary1;
        ans = std::stoi(binary1, nullptr, 2);
        return ans;
    }
};
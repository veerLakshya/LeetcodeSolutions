class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        map<int,int> freq;
        for(auto i: digits) freq[i]++;
        auto pos = [&](int x)->bool{
            map<int,int> req;
            int y = x;
            while(y > 0){
                req[y%10]++;
                y /= 10;
            }
            for(auto i : req){
                if(freq[i.first] < i.second) return false;
            }
            return true;
        };
        vector<int> ans;
        for(int i = 100; i < 1000; i+=2){
            if(pos(i)) ans.push_back(i);
        }
    return ans;
    }
};
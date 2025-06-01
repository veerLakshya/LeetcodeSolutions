class Solution {
public:
    long double t;
    bool h(int i, long double s1, long double s2, vector<int> a){
        if(i == a.size()){
            // cout << s1 << " "<< s2 << endl;
            if(s1 == t && s2 == t) return true;
            else return false;
        }
        bool f = 0;
        f |= h(i + 1, s1*a[i], s2, a);
        f |= h(i + 1, s1, s2*a[i], a);
        return f;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        t = target;
        return h(0,1,1,nums);
    }
};
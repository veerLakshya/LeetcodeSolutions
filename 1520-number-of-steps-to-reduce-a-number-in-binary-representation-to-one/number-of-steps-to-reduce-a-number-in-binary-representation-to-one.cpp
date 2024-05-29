class Solution {
public:
    void odd(string& s){
        int i=s.size()-1;
        while(i>=0 && s[i]!='0'){
            s[i]='0';
            i--;
        }
        if(i<0)s='1'+s;
        else s[i]='1';
    }
    int numSteps(string s) {
        int n= s.size();
        int ans=0;
        while(s.size()>1){
            n=s.size();
            if(s[n-1]=='0')s.pop_back();
            else odd(s);
            ans++;
        }
        return ans;
    }
};
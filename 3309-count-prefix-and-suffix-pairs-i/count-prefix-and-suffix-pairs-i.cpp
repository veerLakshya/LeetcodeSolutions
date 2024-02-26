class Solution {
public:
    bool isp(string &s1,string &s2)
    {
        int n=s1.length();
        int m=s2.length();
        if(m<n) return false;
        string x = s2.substr(0, n);
        string y = s2.substr(m-n);
        return s1==x && s1==y;

    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(isp(words[i],words[j]))count++;
            }
        }
        return count;
    }
};
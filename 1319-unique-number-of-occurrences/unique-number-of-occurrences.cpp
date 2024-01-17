class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector <int> v;
        sort(arr.begin(),arr.end());

        int prev = arr[0];
        int count= 0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] == prev)
            count++;
            else
            {
                v.push_back(count);
                count=1;
            }
            prev = arr[i];
        }
        v.push_back(count);
        
        sort(v.begin(),v.end());

        for(int i=1;i<v.size();i++)
            if(v[i]==v[i-1]) return false;

        return true;
    }
};
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> arr;
        int ans=0;
        for(auto i:boxTypes){
            arr.push_back({i[1],i[0]});
        }
        sort(arr.begin(),arr.end());
        
        for(auto i:arr)cout<< i.first<<" "<<i.second<<endl;
        // return ans;
        cout<<endl;
        int i=arr.size()-1;
        while(truckSize>0 && i>=0){
            ans+= arr[i].first;
            arr[i].second--;
            truckSize--;
            if( arr[i].second==0)i--;
        }
        for(auto i:arr)cout<< i.first<<" "<<i.second<<endl;
        return ans;
        
    }
};
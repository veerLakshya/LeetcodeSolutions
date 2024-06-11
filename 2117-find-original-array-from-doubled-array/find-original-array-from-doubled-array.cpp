class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
        vector<int> ans;
        if(changed.size()==0 || changed.size()==1 || changed.size()%2)return ans;
        multiset<int> pos,neg;
        bool flag = 0;
        for(int i=0;i<changed.size();i++){
            if(changed[i]>=0)pos.insert(changed[i]);
            else if(changed[i]<0) neg.insert(changed[i]);
        }
        while(pos.size()){
            // for(auto i:pos)cout<<i<<" ";
            int x = *pos.begin();
            pos.erase(pos.find(x));
            if(pos.find(2*x)==pos.end()){
                return {};
            }
            ans.push_back(x);
            pos.erase(pos.find(x*2));
        }
        while(neg.size()){
            int x = *pos.end();
            pos.erase(pos.find(x));
            if(pos.find(2*x)==pos.end()){
                return {};
            }
            ans.push_back(x);
            pos.erase(pos.find(x*2));
        }
        return ans;
        
    }
};
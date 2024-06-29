class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, ans = INT_MAX;
        deque <int> dq;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            dq.push_back(nums[i]);
            if(sum >= target){
                do{
                cout<<"sum: "<<sum<<" size: "<<dq.size()<<endl;
                    ans = min( ans, (int)dq.size() );
                    sum -= dq.front();
                    dq.pop_front();
                }while(sum >= target);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int b = blue, r = red;
        int ans = 0;
        for(int i = 1;i<100000;i++){
            if(i&1){
                if(i>blue)break;
                blue-=i;
            }
            else {
                if(i>red)break;
                red-=i;
            }
            ans= max(ans,i);
        }
        for(int i = 1;i<100000;i++){
            if(i&1){
                if(i>r)break;
                r-=i;
            }
            else {
                if(i>b)break;
                b-=i;
            }
            ans= max(ans,i);
        }
        return ans;
    }
};
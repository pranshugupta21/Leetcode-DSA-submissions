class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2) return 0;
        int l=1,r=n-2,maxleft=height[0],maxright=height[n-1];
        int water=0;
        while(l<=r){
            if(maxleft<=maxright){
                if(height[l]>=maxleft){
                    maxleft=height[l];
                }
                else{
                    water+=maxleft-height[l];
                }
                l++;
            }
            else{
               if(height[r]>=maxright){
                maxright=height[r];
               }
               else{
                water+=maxright-height[r];
               }
               r--;
            }
        }
        return water;
    }
};
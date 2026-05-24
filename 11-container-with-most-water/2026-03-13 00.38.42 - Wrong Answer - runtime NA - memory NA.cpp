class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int area=INT_MIN;
        while(l<r){
            int width=r-l;
            int h=min(height[l],height[r]);
            int a=width*h;
            area=max(area,a);
            l++;
            r--;
        }
        return area;
    }
};
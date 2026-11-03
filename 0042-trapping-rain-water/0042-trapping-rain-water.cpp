class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefixmax(n);
        vector<int> suffixmax(n);
        prefixmax[0]=height[0];
        for(int i=1;i<n;i++){
            prefixmax[i]=max(height[i],prefixmax[i-1]);
        }
        suffixmax[n-1]=height[n-1];
        for(int j=n-2;j>=0;j--){
            suffixmax[j]=max(height[j],suffixmax[j+1]);
        }
        int t=0;
        for(int i=1;i<=n-1;i++){
            t+=min(prefixmax[i],suffixmax[i])-height[i];
        }
        return t;
    }
};
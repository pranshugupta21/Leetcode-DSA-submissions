class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n=nums.size(),m=changeIndices.size();
        for(auto &ele:changeIndices) ele--;    // changing to zeroidx
        int low=0,high=m-1,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canmarkall(nums,changeIndices,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return (ans==-1) ? -1:ans+1;
    }
    private:
        bool canmarkall(vector<int>&nums,vector<int>&changeIndices,int k){
        int n=nums.size();
        vector<int>lastocc(n,-1);
        for(int i=0;i<=k;i++){
            lastocc[changeIndices[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(lastocc[i]==-1) return false;  // if idx is not in changeindices
        }
        int availableops=0,completed=0;
        for(int i=0;i<=k;i++){
         int idx=changeIndices[i];
         if(i==lastocc[idx]){
           int decrementneeded=nums[idx];
           if(decrementneeded>availableops) return false;
           availableops-=decrementneeded;
           completed++;
         }
         else{
            availableops++;
         }
         
        }
        return completed==n;
    }
};
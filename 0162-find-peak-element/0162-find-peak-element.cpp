class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid==n-1||nums[mid]>nums[mid+1]){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
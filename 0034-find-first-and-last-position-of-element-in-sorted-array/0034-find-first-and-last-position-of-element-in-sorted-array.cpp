class Solution {
    int firstidx(vector<int>&nums,int target){
        int n=nums.size();
        int first=-1;
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else high=mid-1;
        }
        return first;
    }
        int lastidx(vector<int>&nums,int target){
        int n=nums.size();
        int last=-1;
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else high=mid-1;
        }
        return last;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int first_idx=firstidx(nums,target);
       if(first_idx==-1)return{-1,-1};
       return{first_idx,lastidx(nums,target)};
    }
};
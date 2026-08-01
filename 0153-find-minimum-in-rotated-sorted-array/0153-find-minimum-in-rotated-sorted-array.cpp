class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<high){

            if(nums[low]<nums[high]) return nums[low]; // belong to sorted portion early exit

            int mid=low+(high-low)/2;
          
            if(nums[mid]>nums[high]){   //we are in left sorted portion the minimum always lies in right sorted portion
            low=mid+1;
            }
            else{
               high=mid;          // we are in right sorted portion the minimum can be mid or or to its left
            }
        }
        return nums[low];
    }
};
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int l=0,r=0,c=0,n=nums.size();
        int valid_len=0;
        while(r<n){
             if(nums[r]>right){
                l=r+1;
                valid_len=0;
             }
           else if(nums[r]>=left){
              valid_len=r-l+1;
              c+=valid_len;
             }
             else{
                c+=valid_len;
             }
           r++;
        }
        return c;
    }
};
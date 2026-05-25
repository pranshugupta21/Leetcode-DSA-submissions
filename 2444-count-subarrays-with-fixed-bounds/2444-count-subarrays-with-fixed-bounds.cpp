class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       int n=nums.size();
       int min_idx=-1;
       int max_idx=-1;
       int bad_idx=-1;
       long long total_subarrays=0;
       for(int i=0;i<n;i++){
        if(nums[i]<minK||nums[i]>maxK){
            bad_idx=i;
        }
        if(nums[i]==minK){
            min_idx=i;
        }
        if(nums[i]==maxK){
            max_idx=i;
        }
        int valid_count=min(min_idx,max_idx)-bad_idx;
        if(valid_count>0){
            total_subarrays+=valid_count;
        }
       }
       return total_subarrays;
    }
};
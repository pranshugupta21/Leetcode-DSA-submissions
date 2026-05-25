class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        long long product=1;
        int count=0;
        if(k<=1) return 0;
        while(j<n){
            product*=nums[j];
            while(product>=k){
                product/=nums[i];
                i++;
            }
           count+=1+j-i;  // total no of subarrays 1 for nums[right]& j-i for subarray between
            j++;
        }
        return count;
    }
};
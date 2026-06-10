class Solution {
    int check(vector<int>&nums,int th,int divisor){
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
          sum+=(nums[i]+divisor-1)/divisor;
          if(sum>th) return 0;
        }
        return sum<=th;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold){//smallest divisor whose sum is less than or equal to threshold
        int n=nums.size();
        int low = 1;//*min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,threshold,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
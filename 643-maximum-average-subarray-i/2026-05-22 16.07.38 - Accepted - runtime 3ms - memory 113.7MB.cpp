class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()<k)return 0.0;
        double avgsum=0,maxavg=0;
        for(int i=0;i<k;i++){
          avgsum+=nums[i];
        }
        maxavg=avgsum;
        int l=0,r=k;
        while(r<nums.size()){
         avgsum-=nums[l];
         avgsum+=nums[r];
         l++;
         r++;
         maxavg=max(avgsum,maxavg);
        }
        return(maxavg/k);
    }
};
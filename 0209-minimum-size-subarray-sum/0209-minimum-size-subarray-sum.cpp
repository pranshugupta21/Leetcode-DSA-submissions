class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int len=INT_MAX,l=0,r=0;
       int n=nums.size();
       long long sum=0;
       long long total_sum=accumulate(nums.begin(),nums.end(),0LL);
       if(total_sum<target)return 0;
       while(r<n){
        sum+=nums[r];
        while(sum>target){
            sum-=nums[l];
           
            len=min(len,r-l+1);
             l++;
        }
        if(sum==target){
        len=min(len,r-l+1);
       }
        r++;
       }
       return len;
    }
};
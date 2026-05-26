class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l=0,n=nums.size();
        int len=0,curr_sum=0;
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        int target=total_sum-x;
        if(target<0) return -1;
        if(target==0) return n;
        for(int r=0;r<n;r++){
            curr_sum+=nums[r];
            while(curr_sum>target && l<=r){
                curr_sum-=nums[l];         // shrink the window 
                l++;
            }
            if(curr_sum==target){          // find longest subarray whose sum is equal to target
                len=max(len,r-l+1);
            }
        }
        return len==0 ? -1:n-len;
        
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int i,j,temp;
        for(i=0;i<n-1;i++)
        {
          for(j=0;j<n-1-i;j++)
          {
            if(nums[j]>nums[j+1])
            {
            swap(nums[j],nums[j+1]);
            }
          }
        }
        for(i=0;i<n;i++)
        {
            if(nums[i]!=i)
            {
                return i;
            }
        }
        return n;
        
    }
};
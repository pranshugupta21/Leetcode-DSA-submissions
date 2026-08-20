class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int i,j;
        int flag;
        for(i=0;i<n;i++)
        {   flag=0;
          for(j=0;j<n;j++)
          {
            if(nums[j]==i)
            {
                flag=1;
                break;
            }
          }
          if(flag==0)
          return i;
        }
           return n; 
    }
};
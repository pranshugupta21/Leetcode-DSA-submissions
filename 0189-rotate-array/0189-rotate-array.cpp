class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i,j,temp;
        int size=nums.size();
        k=k%size;
        for(i=0,j=size-1;i<j;i++,j--)
        {
          temp=nums[i];
          nums[i]=nums[j];
          nums[j]=temp;
        }
        for(i=0,j=k-1;i<j;i++,j--)
        {
          temp=nums[i];
          nums[i]=nums[j];
          nums[j]=temp;
        }
        for(i=k,j=size-1;i<j;i++,j--)
        {
          temp=nums[i];
          nums[i]=nums[j];
          nums[j]=temp;
        }
       

        
    }
};
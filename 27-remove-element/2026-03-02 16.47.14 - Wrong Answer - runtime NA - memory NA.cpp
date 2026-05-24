class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size()-1;
        int left=0;
        int right=n-1;
        int count=0;
        while(left<right){
            if(nums[left]!=val) left++;
            else if(nums[right]==val) right--;
            else{
                swap(nums[left],nums[right]);
                count++; 
                left++;
                right--;
            }
        }
       int ans=n-count;
       return ans>0 ?  ans: 0;
           
        }
    
};
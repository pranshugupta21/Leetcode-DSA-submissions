class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>arr(nums.size());// creat a new array of same length
        int j=0,k=1;// j is for positive number ank k for neg num for new array
       for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
           arr[j]=nums[i];
           j+=2;
        }
        else if(nums[i]<0){
         arr[k]=nums[i];
         k+=2;
        }
       }
       return arr; 
    }
};
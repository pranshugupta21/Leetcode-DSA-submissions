class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0,k=0;
        int j=1;
        int n=nums.size();
        while(i<n&&j<n){
            if(nums[k]%2==0){
               swap(nums[k],nums[i]);
               i+=2;
               k++;
            }
            else{
                swap(nums[k],nums[j]);
                j+=2;
                k++;
            }
        }
        return nums;

    }
};
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        for(int k=0;k<nums.size();k++){
            if(nums[k]%2==0){
                swap(nums[k],nums[i]);
                i++;
            }
        }
        return nums;
    }
};
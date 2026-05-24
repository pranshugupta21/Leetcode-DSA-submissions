class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        for(int j=0;j<nums.size();j++){
            if(nums[j]%2==0&&mp[nums[j]]==1){
                return nums[j];
            }
        }
        return -1;
    }
};
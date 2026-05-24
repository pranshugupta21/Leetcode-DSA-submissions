class Solution {
public:
    int missingInteger(vector<int>& nums) {
      unordered_map<int,int>mp;
      for(int i:nums){
        mp[i]++;
      }
       int sum=nums[0];
      for(int j=1;j<nums.size();j++){
        if(nums[j]==nums[j-1]+1){
            sum+=nums[j];   
        }
        else{
            break;
        }
      }
      while(mp.count(sum)!=0){
        sum+=1;
      }
return sum;

    }
};
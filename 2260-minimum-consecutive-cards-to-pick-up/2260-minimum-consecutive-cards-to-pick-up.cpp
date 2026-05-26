class Solution {
public:
    int minimumCardPickup(vector<int>& nums) {
        int l=0,n=nums.size();
        unordered_map<int,int>mp;
        int len=INT_MAX;
          for(int r=0;r<n;r++){

          if(mp.find(nums[r])!=mp.end()){
            len=min(len,r-mp[nums[r]]+1);
          }
          
          mp[nums[r]]=r;
          
        }
        return len==INT_MAX? -1:len;
    }
};
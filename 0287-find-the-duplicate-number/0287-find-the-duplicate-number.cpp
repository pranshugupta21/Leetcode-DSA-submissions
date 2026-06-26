class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int n=nums.size();
      vector<bool>seen(n+1,false);
      for(auto n:nums){
        if(seen[n]) return n;
        seen[n]=true;
      }
      return 0;
    }
};
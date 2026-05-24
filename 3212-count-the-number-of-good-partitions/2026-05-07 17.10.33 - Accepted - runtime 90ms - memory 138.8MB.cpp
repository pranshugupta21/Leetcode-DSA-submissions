class Solution {
public:
    int m=1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
      int  i=0;
        int res=1;
       int j=0;
        while(i<n){
         if(i>j){
            res=(res*2)%(m);
         }
         j=max(j,mp[nums[i]]);
         i++;
        }
       return res; 
    }
};
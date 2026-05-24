class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
     //   vector<int>prefixsum(n+1,0);
        int ans=0;
        unordered_map<int,int>mp;
      /*  for(int i=1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+nums[i-1];
        }*/
        for(int i=0;i<n;i++){
            int prefixsum=0;
            for(int j=i;j<n;j++){
                prefixsum+=nums[j];
                 if (prefixsum%k==0){
                    ans++;
                 }
            }
        }
       return ans;
    }
};
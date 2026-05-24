class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
       int n=nums.size();
       long long ans=0;
       long long prefix_xor=0;
       vector<int>mp(1<<20,0);
       mp[0]=1;
       for(int i=0;i<n;i++){
        prefix_xor^=nums[i];
        ans+=mp[prefix_xor]++;
       } 
       return ans;
    }
};
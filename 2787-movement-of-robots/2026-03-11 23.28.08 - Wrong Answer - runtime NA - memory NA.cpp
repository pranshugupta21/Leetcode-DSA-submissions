typedef long long int ll;
 const ll MOD=1e9+7;
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n=nums.size();
        for(ll i=0;i<n;i++){
           if(s[i]=='L'){
           nums[i]=(ll)(nums[i]-d);
           }
           else{
           nums[i]=(ll)(nums[i]+d);
           }
        }
       sort(nums.begin(),nums.end());
       ll prefixsum=0;
       ll ans=0;
       for(ll j=0;j<n;j++){
        ans+=(((j%MOD)*nums[j]%MOD)-prefixsum%MOD)%MOD;
        prefixsum+=nums[j];
       }
       return ans;  
    }
};
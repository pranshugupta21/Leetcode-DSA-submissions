typedef long long int ll;
 const ll MOD=1e9+7;
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n=nums.size();
        vector<ll>pos(n);
        for(int i=0;i<n;i++){
          pos[i]= s[i]=='L'? (ll)nums[i]-d:(ll)nums[i]+d;
        }
       sort(pos.begin(),pos.end());
       ll prefixsum=0;
       ll ans=0;
       for(ll j=0;j<n;j++){
        ans=(ans+(((j%MOD)*pos[j]%MOD)%MOD)-(prefixsum%MOD)+MOD)%MOD;
        prefixsum+=pos[j];
       }
       return ans;  
    }
};
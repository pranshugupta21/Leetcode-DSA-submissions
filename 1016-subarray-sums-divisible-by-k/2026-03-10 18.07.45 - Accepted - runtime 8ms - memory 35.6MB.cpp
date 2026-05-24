class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;  
        unordered_map<int,int>freq;
        freq[0]=1;
        int prefixsum=0;
        for(int i=0;i<n;i++){
             prefixsum+=nums[i];
             int mod=((prefixsum%k)+k)%k;
             ans+=freq[mod];
             freq[mod]++;
            }
            return ans;
        }
       
    
};
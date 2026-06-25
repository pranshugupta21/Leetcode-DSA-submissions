class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
        long long minl=1LL*lower-nums[i];
        long long maxu=1LL*upper-nums[i];
        long long low=lower_bound(nums.begin()+i+1,nums.end(),minl)-nums.begin(); // COUNT UNIQUE PAIRS MOVING FORWARD
        long long high=upper_bound(nums.begin()+i+1,nums.end(),maxu)-nums.begin();
        ans+=high-low;
        }
        return ans;
    }
};
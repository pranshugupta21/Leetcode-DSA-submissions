class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int target=(accumulate(nums.begin(),nums.end(),0))%p;
        if (target==0) return 0;
        unordered_map<int,int> mp;
        mp[-1]=0;
        long long prefix=0;
        int minlen=n;
        for(int j=0;j<n;j++){
            prefix+=nums[j];
            int curr=prefix%p;
            int need=(curr-target+p)%p;
            if(mp.count(need)){
                minlen=min(minlen,j-mp[need]);
            }
            mp[curr]=j;
        }
       return minlen==n?-1:minlen;

    }
};
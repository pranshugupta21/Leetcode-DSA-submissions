class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        bool w=true;
        long long sum=0,maxsum=0;
        for(int i=0;i<k;i++){
           if(mp.find(nums[i])!=mp.end()){
            w=false;
           } 
           mp[nums[i]]++;
           sum+=nums[i];
        }
        if(w){
            maxsum=sum;
        }
        int l=0,r=k-1;
        for(int i=1;i<=n-k;i++){
            sum=sum-nums[l]+nums[r+1];
            mp[nums[l]]--;
            
            if(mp.find(nums[r+1])==mp.end()){
             maxsum=max(maxsum,sum);
            }
             mp[nums[r+1]]++;
            l++;
            r++;
        }
        return maxsum;
    }
};
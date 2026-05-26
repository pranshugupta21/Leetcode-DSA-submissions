class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,sum=0,score=0;
        unordered_map<int,int>mp;
        for(int r=0;r<n;r++){
          if(mp.find(nums[r])==mp.end()){
            sum+=nums[r];
            mp[nums[r]]++;
          }
          else{
            while(mp.find(nums[r])!=mp.end()){
                mp[nums[l]]--;
                sum-=nums[l];
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            sum+=nums[r];
            mp[nums[r]]++;
          }
          score=max(score,sum);
        }
        return score;
    }
};
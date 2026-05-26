class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int freq[2]={0};
        int l=0,r=0,n=nums.size();
        int c=0,maxc=0;
        for(int r=0;r<n;r++){
            freq[nums[r]]++;
            if(nums[r]==1)c++;

            if(nums[r]==0){
             while(freq[0]>1){
              if(nums[l]==1)c--;
              freq[nums[l]]--;
              l++;
            }
            }

            maxc=max(maxc,c);
        }
        if(freq[0]==0) return n-1;
        return maxc;
    }
};
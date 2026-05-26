class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,sum=0,score=0;
        vector<int>window(10001,0);
        for(int r=0;r<n;r++){
            while(window[nums[r]]>0){
                window[nums[l]]--;
                sum-=nums[l];
                l++;
            }
            sum+=nums[r];
            window[nums[r]]++;
          score=max(score,sum);
        }
        return score;
    }
};
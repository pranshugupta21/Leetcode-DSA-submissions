class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        int sum=accumulate(nums.begin(),nums.end(),0);
        int prefixsum=0;
        for(int i = 0; i < n; i++){
            int leftCount  = i;
            int rightCount = n - 1 - i;
            int leftSum    = prefixsum;
            int rightSum   = sum-prefixsum-nums[i];

            int ans = (nums[i] * leftCount - leftSum)
                    + (rightSum - nums[i] * rightCount);

            result.push_back(ans);
            prefixsum+=nums[i];
        }
        return result;
    }
};
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        vector<int> left(n+1, 0);
        vector<int> right(n+1, 0);

        // prefix sum
        for(int i = 1; i < n+1; i++)
            left[i] = left[i-1] + nums[i-1];

        // suffix sum
        for(int i = n-1; i >= 0; i--)
            right[i] = right[i+1] + nums[i];

        // left[i]   = sum of elements strictly before i
        // right[i+1]= sum of elements strictly after i
        for(int i = 0; i < n; i++){
            int leftCount  = i;
            int rightCount = n - 1 - i;
            int leftSum    = left[i];
            int rightSum   = right[i+1];

            int ans = (nums[i] * leftCount - leftSum)
                    + (rightSum - nums[i] * rightCount);

            result.push_back(ans);
        }
        return result;
    }
};
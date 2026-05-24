class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int last1 = -1, last2 = -1;
        int minn = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                last1 = i;
                if (last2 != -1) {
                    minn = min(minn, abs(last1 - last2));
                }
            } else if (nums[i] == 2) {
                last2 = i;
                if (last1 != -1) {
                    minn = min(minn, abs(last1 - last2));
                }
            }
        }
        return minn;
    }
};

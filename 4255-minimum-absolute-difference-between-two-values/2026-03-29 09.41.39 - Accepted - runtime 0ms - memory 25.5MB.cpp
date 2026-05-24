class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int min_diff = 1e9; // Representing infinity
        int last_1 = -1;
        int last_2 = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                last_1 = i;
                if (last_2 != -1) {
                    min_diff = min(min_diff, i - last_2);
                }
            } else if (nums[i] == 2) {
                last_2 = i;
                if (last_1 != -1) {
                    min_diff = min(min_diff, i - last_1);
                }
            }
        }

        return min_diff == 1e9 ? -1 : min_diff;
    }
};

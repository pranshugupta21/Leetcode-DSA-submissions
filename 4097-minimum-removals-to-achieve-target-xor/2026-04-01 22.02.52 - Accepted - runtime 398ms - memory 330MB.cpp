class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int max_xor = 16384; 
        vector<int> dp(max_xor, 1e9);
        dp[0] = 0;
        for (int num : nums) {
            vector<int> next_dp(max_xor, 1e9);
            for (int x = 0; x < max_xor; ++x) {
                if (dp[x] != 1e9) {
                    next_dp[x] = min(next_dp[x], dp[x] + 1);
                    next_dp[x ^ num] = min(next_dp[x ^ num], dp[x]);
                }
            }
            dp = next_dp;
        }
        return dp[target] == 1e9 ? -1 : dp[target];
    }
};
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        
        // Use long long to prevent overflow
        vector<long long> rightProd(n, 1);
        long long MAX_SUM = 1e14; // The maximum possible left sum (10^5 * 10^9)
        
        // Build the strictly right product array from right to left
        for (int i = n - 2; i >= 0; i--) {
            // Guard against overflow: check before multiplying
            if (nums[i + 1] > MAX_SUM / rightProd[i + 1]) {
                rightProd[i] = MAX_SUM + 1; // Cap it since it's too big to ever match a left sum
            } else {
                rightProd[i] = rightProd[i + 1] * nums[i + 1];
            }
        }
        
        long long currentLeftSum = 0;
        
        // Traverse left to right to find the *first* (smallest) balanced index
        for (int i = 0; i < n; i++) {
            if (currentLeftSum == rightProd[i]) {
                return i;
            }
            // Add current number to left sum for the next iteration
            currentLeftSum += nums[i]; 
        }
        
        return -1;
    }
};

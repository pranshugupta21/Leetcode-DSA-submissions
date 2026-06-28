class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
   int n = nums.size();
        const long long INF = 1e16; // Safe lower bound for 64-bit integers

        // Helper lambda to run our DP for a specific operation
        auto get_max_overlap = [&](function<long long(long long)> op) {
            long long no_op = -INF;
            long long in_op = -INF;
            long long post_op = -INF;
            long long max_sum = -INF;

            for (int i = 0; i < n; ++i) {
                long long x = nums[i];
                long long v = op(x);
                
                // Transitions
                long long new_no_op = max(x, no_op + x);
                // max with initializer list for >2 elements
                long long new_in_op = max({v, no_op + v, in_op + v}); 
                long long new_post_op = max(in_op + x, post_op + x);

                // Update states
                no_op = new_no_op;
                in_op = new_in_op;
                post_op = new_post_op;

                // We only care about states where at least 1 element was operated on
                if (in_op > max_sum) max_sum = in_op;
                if (post_op > max_sum) max_sum = post_op;
            }
            return max_sum;
        };

        // Calculate standard max subarray and track its shortest possible length
        long long max_orig = -INF;
        int min_len = n + 1;
        long long curr_sum = 0;
        int curr_len = 0;

        for (int i = 0; i < n; ++i) {
            long long x = nums[i];
            if (x > curr_sum + x) {
                curr_sum = x;
                curr_len = 1;
            } else if (x == curr_sum + x) { // Resetting length is optimal if sum is equivalent
                curr_sum = x;
                curr_len = 1;
            } else {
                curr_sum += x;
                curr_len += 1;
            }

            if (curr_sum > max_orig) {
                max_orig = curr_sum;
                min_len = curr_len;
            } else if (curr_sum == max_orig) {
                min_len = min(min_len, curr_len);
            }
        }

        long long ans = -INF;
        
        // Option 1: Overlapping Multiplication
        ans = max(ans, get_max_overlap([&](long long x) { return x * k; }));
        
        // Option 2: Overlapping Division
        // C++ natively truncates towards zero (floor for positive, ceil for negative)
        ans = max(ans, get_max_overlap([&](long long x) { return x / k; }));
        
        // Option 3: Disjoint Operation (Only valid if we don't have to touch the max subarray)
        if (min_len < n) {
            ans = max(ans, max_orig);
        }

        return ans;
    }
};
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // Optimize standard C++ I/O operations for competitive programming
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        // Stores the last seen index of an element + 1 (0 means unseen)
        vector<int> last_pos(100001, 0); 
        
        long long current_sum = 0;
        long long max_sum = 0;
        int left = 0; // Left boundary of our sliding window

        for (int right = 0; right < n; ++right) {
            int current_val = nums[right];
            
            // If the element was seen inside our current window, 
            // snap the left pointer past its previous occurrence
            if (last_pos[current_val] > left) {
                while (left < last_pos[current_val] - 1) {
                    current_sum -= nums[left];
                    left++;
                }
                left++; // Move left exactly past the duplicate
            } else {
                current_sum += current_val;
            }

            // Update the element's last seen position (1-indexed)
            last_pos[current_val] = right + 1;

            // Check if our valid, duplicate-free window hit size k
            if (right - left + 1 == k) {
                max_sum = max(max_sum, current_sum);
                // Prepare for the next iteration by sliding the left pointer up
                current_sum -= nums[left];
                left++;
            }
        }

        return max_sum;
    }
};
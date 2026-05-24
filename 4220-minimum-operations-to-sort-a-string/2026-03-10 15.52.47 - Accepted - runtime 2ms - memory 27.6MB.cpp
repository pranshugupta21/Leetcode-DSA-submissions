#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.length();
        
        // 0 operations: Already sorted
        if (std::is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // -1 case: If length is 2 and not sorted, it's impossible 
        // because we can't sort the whole string.
        if (n == 2) return -1;

        char min_char = *std::min_element(s.begin(), s.end());
        char max_char = *std::max_element(s.begin(), s.end());

        // 1 operation: Boundary already contains a correct "anchor"
        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }

        // 3 operations: The "Absolute Worst Case"
        // This only happens if s[0] is the max AND s[n-1] is the min
        // AND there are no other mins/maxes we can "pull" to the edges in 1 step.
        if (s[0] == max_char && s[n - 1] == min_char) {
            bool min_in_middle = false;
            for (int i = 1; i < n - 1; ++i) {
                if (s[i] == min_char) min_in_middle = true;
            }

            bool max_in_middle = false;
            for (int i = 1; i < n - 1; ++i) {
                if (s[i] == max_char) max_in_middle = true;
            }

            // If we can pull a min to the front or max to the back in one move, it's 2.
            // Otherwise, it takes 3 (like "cba").
            if (min_in_middle || max_in_middle) return 2;
            return 3;
        }

        // 2 operations: Standard unsorted case
        return 2;
    }
};
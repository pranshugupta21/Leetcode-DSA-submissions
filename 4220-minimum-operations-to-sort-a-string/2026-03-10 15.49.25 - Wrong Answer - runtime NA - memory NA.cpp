#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.length();
        if (n <= 1) return 0;
        if (std::is_sorted(s.begin(), s.end())) {
            return 0;
        }

        char min_char = *std::min_element(s.begin(), s.end());
        char max_char = *std::max_element(s.begin(), s.end());
        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }
        if (n == 2) {
            return -1;
        }
        if (s[0] == max_char && s[n - 1] == min_char) {
            return 3;
        }
        return 2;
    }
};
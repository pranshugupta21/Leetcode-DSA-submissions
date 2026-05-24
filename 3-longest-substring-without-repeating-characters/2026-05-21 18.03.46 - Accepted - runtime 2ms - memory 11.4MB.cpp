class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); 
        int maxLen = 0, left = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            // if character was seen, move left pointer
            if (lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }
            lastIndex[c] = right; // update last seen index
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

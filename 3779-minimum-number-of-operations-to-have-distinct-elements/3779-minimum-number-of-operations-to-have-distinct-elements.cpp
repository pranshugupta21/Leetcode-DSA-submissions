
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        int dupCount = 0;

        // Count frequencies
        for (int x : nums) {
            freq[x]++;
        }

        // Count how many numbers have freq >= 2
        for (auto &p : freq) {
            if (p.second >= 2) dupCount++;
        }

        // Already all distinct
        if (dupCount == 0) return 0;

        int ops = 0;
        int i = 0;
        int n = nums.size();

        // Remove in chunks of 3
        while (i < n && dupCount > 0) {
            for (int j = 0; j < 3 && i < n; j++, i++) {
                int val = nums[i];
                if (freq[val] == 2) dupCount--; // going from duplicate to unique
                freq[val]--;
            }
            ops++;
        }

        return ops;
    }
};

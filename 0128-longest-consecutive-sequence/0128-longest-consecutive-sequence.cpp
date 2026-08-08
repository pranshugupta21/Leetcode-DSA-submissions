class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> st;
        for(int x : nums) st.insert(x);
        int longest = 0;

// Iterate over the set to avoid redundant checks for dup
        for(int it : st) {
 // Only start counting if 'it' is the start of a sequence
            if(st.find(it - 1) == st.end()){
                int current = it;
                int count = 0;
                while(st.find(current) != st.end()){
                    current++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
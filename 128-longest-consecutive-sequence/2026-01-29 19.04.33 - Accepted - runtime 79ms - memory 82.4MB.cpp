class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        // 1. Initialize set and reserve space to prevent frequent rehashing
        unordered_set<int> st;
        st.reserve(n); 
        for(int x : nums) st.insert(x);

        int longest = 0;

        // 2. Iterate over the set to avoid redundant checks for duplicates
        for(int it : st) {
            // 3. Only start counting if 'it' is the start of a sequence
            if(st.find(it - 1) == st.end()){
                int current = it;
                int count = 0;

                // 4. Use a more efficient check for the next element
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
class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();
        
        // stores {OR_value, leftmost_index_that_produces_this_OR}
        // These are OR sums ending at the current index
        vector<pair<int, int>> curr_ors; 
        
        // To check "Present in Subarray", we need the last seen index of each value
        map<int, int> last_seen;

        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            last_seen[val] = i;
            
            vector<pair<int, int>> next_ors;
            next_ors.push_back({val, i});
            
            for (auto& p : curr_ors) {
                int new_or = p.first | val;
                if (new_or != next_ors.back().first) {
                    next_ors.push_back({new_or, p.second});
                } else {
                    // Keep the leftmost index for the same OR value
                    next_ors.back().second = p.second;
                }
            }
            curr_ors = next_ors;

            // For each distinct OR value ending at i, check if it's "Good"
            // The OR value 'v' spans from index 'start' to 'end' (where 'end' 
            // is the 'start' of the next OR value in the list)
            int end_idx = i;
            for (int k = 0; k < curr_ors.size(); ++k) {
                int v = curr_ors[k].first;
                int start_idx = curr_ors[k].second;
                int next_start = (k + 1 < curr_ors.size()) ? curr_ors[k+1].second : -1;
                
                // If the value 'v' was last seen at an index >= start_idx,
                // then all subarrays starting between [next_start + 1, start_idx]
                // and ending at 'i' are GOOD.
                if (last_seen.count(v) && last_seen[v] >= start_idx) {
                    count += (start_idx - next_start);
                }
                
                end_idx = start_idx - 1;
            }
        }
        return count;
    }
};
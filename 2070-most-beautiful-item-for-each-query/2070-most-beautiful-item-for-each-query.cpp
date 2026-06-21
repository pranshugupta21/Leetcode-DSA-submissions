class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
       sort(items.begin(), items.end());
        
        // 2. Pass through and update beauty to be the "prefix maximum" beauty
        int max_beauty_so_far = 0;
        for (int i = 0; i < items.size(); i++) {
            max_beauty_so_far = max(max_beauty_so_far, items[i][1]);
            items[i][1] = max_beauty_so_far; 
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        // 3. Process each query using binary search
        for (int q : queries) {
            // We want the first item with a price GREATER than q, then we step back 1
            // We use {q, INT_MAX} as our dummy pair target
            auto it = upper_bound(items.begin(), items.end(), vector<int>{q, INT_MAX});
            // vector<int>{q, INT_MAX} let you compare only through prices it bypasses all elem:prices <= q
            if (it == items.begin()) {
                // All items are more expensive than our query price `q`
                //query is actually the smallest so no items is<= but upperbound points to first bcz 1st elem> q uery so it will be push back 0
                ans.push_back(0);
            } else {
                // Move back one step to get the item where price <= q
                it--;
                ans.push_back((*it)[1]); // Grab its pre-calculated max beauty
            }
        }
        
        return ans;
    }
};
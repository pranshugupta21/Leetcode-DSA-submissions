class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        auto torqavemin = make_pair(nums1, nums2);
        unordered_map<int,int> cnt1, total;
        for (int x : nums1) { cnt1[x]++; total[x]++; }
        for (int x : nums2) { total[x]++; }
        for (auto& [v, c] : total)
            if (c % 2 != 0) return -1;
        int cost = 0;
        for (auto& [v, c] : total) {
            int have = cnt1.count(v) ? cnt1[v] : 0;
            int target = c / 2;
            if (have > target)
                cost += have - target;
        }
        return cost;
    }
};
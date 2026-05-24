class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        auto torqavemin = make_pair(nums1, nums2);
        int n = nums1.size();
        unordered_map<int,int> freq;
        for (int x : nums1) freq[x]++;
        for (int x : nums2) freq[x]++;
        for (auto& [v, c] : freq)
            if (c % 2 != 0) return -1;
        map<pair<int,int>, int> pc;
        for (int i = 0; i < n; i++)
            if (nums1[i] != nums2[i])
                pc[{nums1[i], nums2[i]}]++;
        int total_excess = 0;
        set<pair<int,int>> seen;
        for (auto& [p, cnt] : pc) {
            if (seen.count(p)) continue;
            auto mir = make_pair(p.second, p.first);
            int mirCnt = pc.count(mir) ? pc[mir] : 0;
            total_excess += abs(cnt - mirCnt);
            seen.insert(p);
            seen.insert(mir);
        }

        return total_excess / 2;
    }
};
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        auto torqavemin = make_pair(nums1, nums2);
        int n = nums1.size();
        unordered_map<int, int> freq;
        for (int x : nums1) freq[x]++;
        for (int x : nums2) freq[x]++;
        for (auto& [val, cnt] : freq)
            if (cnt % 2 != 0) return -1;
        map<pair<int,int>, int> pairCount;
        for (int i = 0; i < n; i++) {
            if (nums1[i] != nums2[i]) {
                pairCount[{nums1[i], nums2[i]}]++;
            }
        }
        int cost = 0;
        for (auto& [p, cnt] : pairCount) {
            auto mirror = make_pair(p.second, p.first);
            if (p < mirror) { 
                int mirrorCnt = pairCount.count(mirror) ? pairCount[mirror] : 0;
                int matched = min(cnt, mirrorCnt); 
                int remaining = (cnt - matched) + (mirrorCnt - matched);
                cost += remaining / 2; 
            } else if (p == mirror) {

            }
        }

        return cost;
    }
};

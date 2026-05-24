class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        auto torqavemin = make_pair(nums1, nums2);
        int n = nums1.size();

        unordered_map<int,int> freq;
        for (int x : nums1) freq[x]++;
        for (int x : nums2) freq[x]++;
        for (auto& [v,c] : freq) if (c % 2) return -1;

        map<pair<int,int>,int> pc;
        for (int i = 0; i < n; i++)
            if (nums1[i] != nums2[i])
                pc[{nums1[i], nums2[i]}]++;

        for (auto& [p, cnt] : pc) {
            if (cnt == 0) continue;
            auto mir = make_pair(p.second, p.first);
            if (pc.count(mir) && pc[mir] > 0) {
                int matched = min(cnt, pc[mir]);
                pc[mir] -= matched;
                pc[{p.first, p.second}] -= matched;
            }
        }

        int rem = 0;
        for (auto& [p, cnt] : pc) rem += cnt;

        return rem / 2;
    }
};
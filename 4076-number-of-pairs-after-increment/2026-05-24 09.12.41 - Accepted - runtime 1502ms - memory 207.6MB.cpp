
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums2.size();
        int sz = max(1, (int)sqrt(n));
        int blocks=(n+sz-1)/sz;
    vector<int> ans;
        vector<unordered_map<long long, int>> freq(blocks);
        vector<long long> shift(blocks, 0);
        
        for (int i = 0; i < n; i++) {
            freq[i/sz][nums2[i]]++;
        }
        for (const auto& q : queries) {
            if (q[0] == 1) {
                int L = q[1];
                int R = q[2];
                long long delta = q[3];
                int bL = L / sz;
                int bR = R / sz;
                if (bL == bR) {
                    for (int i = L; i <= R; i++) {
                        freq[bL][nums2[i]]--;
                        nums2[i] += delta;
                        freq[bL][nums2[i]]++;
                    }
                } else {
                    int endL = (bL + 1) * sz - 1;
                    for (int i = L; i <= endL; i++) {
                        freq[bL][nums2[i]]--;
                        nums2[i] += delta;
                        freq[bL][nums2[i]]++;
                    }
                    for (int b = bL + 1; b < bR; b++) {
                        shift[b] += delta;
                    }
                    int startR = bR * sz;
                    for (int i = startR; i <= R; i++) {
                        freq[bR][nums2[i]]--;
                        nums2[i] += delta;
                        freq[bR][nums2[i]]++;
                    }
                }
            } 
            else {
                long long target = q[1];
                long long total_pairs = 0; 
                for (int x : nums1) {
                    long long needed = target - x;
                    for (int b = 0; b < blocks; b++) {
                        long long val = needed - shift[b];
                        auto it = freq[b].find(val);
                        if (it != freq[b].end()) {
                            total_pairs += it->second;
                        }
                    }
                }
                ans.push_back(total_pairs);
            }
        }
        return ans;
    }
};

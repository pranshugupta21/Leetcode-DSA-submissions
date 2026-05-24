class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int prefix_xor = 0;
        
        // Since max nums[i] <= 10^6, the XOR sum will never exceed 2^20 (1,048,576)
        // A direct vector acts as a perfect, ultra-fast hash map
        vector<int> count(1 << 20, 0); 
        count[0] = 1; // Base case for empty prefix
        
        for (int i = 0; i < n; i++) {
            prefix_xor ^= nums[i];
            ans += count[prefix_xor]++;
        } 
        
        return ans;
    }
};
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        
        // Try rotating by every position 0 to n-1
        for(int rot = 0; rot < n; rot++) {
            bool sorted = true;
            
            // Check if this rotation gives sorted array
            for(int i = 0; i < n-1; i++) {
                if(nums[(i + rot) % n] > nums[(i + rot + 1) % n]) {
                    sorted = false;
                    break;
                }
            }
            
            if(sorted) return true;
        }
        return false;
    }
};
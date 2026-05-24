class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
           int mid = low + (high - low) / 2; // find mid
                            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;// when the loop ends this is the index where the element will get inserted
    }
};
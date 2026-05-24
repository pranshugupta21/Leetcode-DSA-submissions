class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for (int x : arr) total += x;

        // If total sum is not divisible by 3, it's impossible
        if (total % 3 != 0) return false;

        int target = total / 3;
        int sum = 0, count = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == target) {
                count++;
                sum = 0;
                // If we already found 2 partitions, the rest must form the 3rd
                if (count == 2 && i < n - 1) return true;
            }
        }

        return false;
    }
};

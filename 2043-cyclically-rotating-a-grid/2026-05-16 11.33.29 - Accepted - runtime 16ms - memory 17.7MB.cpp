class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        for (int p = 0; p < min(m, n) / 2; p++) {
            vector<int> nums;

            // Extract ring elements in clockwise order
            for (int j = p; j < n - p - 1; j++)  nums.push_back(grid[p][j]);
            for (int i = p; i < m - p - 1; i++)  nums.push_back(grid[i][n-p-1]);
            for (int j = n-p-1; j > p; j--)      nums.push_back(grid[m-p-1][j]);
            for (int i = m-p-1; i > p; i--)      nums.push_back(grid[i][p]);

            // Counter-clockwise rotation = left rotate array by (k % size)
            int l = nums.size();
            int shift = k % l;
            if (shift == 0) continue;

            rotate(nums.begin(), nums.begin() + shift, nums.end());

            // Write back
            int idx = 0;
            for (int j = p; j < n - p - 1; j++)  grid[p][j]     = nums[idx++];
            for (int i = p; i < m - p - 1; i++)  grid[i][n-p-1] = nums[idx++];
            for (int j = n-p-1; j > p; j--)      grid[m-p-1][j] = nums[idx++];
            for (int i = m-p-1; i > p; i--)      grid[i][p]     = nums[idx++];
        }

        return grid;
    }
};
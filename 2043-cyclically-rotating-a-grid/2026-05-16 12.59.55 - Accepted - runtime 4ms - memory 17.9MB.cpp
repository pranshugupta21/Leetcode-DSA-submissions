class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers=min(m,n)/2;
        for (int layer = 0; layer<layers;layer++) {
            vector<int> nums;
            int top=layer;
            int right=n-layer-1;
            int left=layer;
            int bottom=m-layer-1;
            for(int i=top;i<=right;i++) nums.push_back(grid[top][i]);
            for(int j=top+1;j<bottom;j++) nums.push_back(grid[j][right]);
            for(int i=right;i>=left;i--) nums.push_back(grid[bottom][i]);
            for(int j=bottom-1;j>top;j--) nums.push_back(grid[j][left]);
            int len=nums.size();
            int shift=k%len;
            if(shift==0) continue;
            rotate(nums.begin(),nums.begin()+shift,nums.end());
           int idx=0;
           for(int i=top;i<=right;i++) grid[top][i]=nums[idx++];
            for(int j=top+1;j<bottom;j++) grid[j][right]=nums[idx++];
            for(int i=right;i>=left;i--) grid[bottom][i]=nums[idx++];
            for(int j=bottom-1;j>top;j--) grid[j][left]=nums[idx++]; 
    }
    return grid;
    }
};
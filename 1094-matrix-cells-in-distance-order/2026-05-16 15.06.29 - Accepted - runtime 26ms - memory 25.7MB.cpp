/*class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int cells=rows*cols;
        vector<vector<int>>ans;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ans.push_back({i,j});
            }
        }
        sort(ans.begin(),ans.end(),[&](vector<int>&a,vector<int>&b){
            int da=abs(a[0]-rCenter)+abs(a[1]-cCenter);
            int db=abs(b[0]-rCenter)+abs(b[1]-cCenter);
            return da<db;
        });
        return ans;
    }
};*/

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        // The maximum possible Manhattan distance in the grid
        int maxDist = rows + cols;
        
        // Buckets where index represents the distance from the center
        vector<vector<vector<int>>> buckets(maxDist);
        
        // Iterate through every cell in the grid
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // Calculate the Manhattan distance
                int dist = abs(r - rCenter) + abs(c - cCenter);
                // Place the cell coordinates in the appropriate bucket
                buckets[dist].push_back({r, c});
            }
        }
        
        // Flatten the buckets into the final result array
        vector<vector<int>> result;
        // Pre-allocate memory to avoid multiple reallocations
        result.reserve(rows * cols); 
        
        for (const auto& bucket : buckets) {
            for (const auto& cell : bucket) {
                result.push_back(cell);
            }
        }
        
        return result;
    }
};
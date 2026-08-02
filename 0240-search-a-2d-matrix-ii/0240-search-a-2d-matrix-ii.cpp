class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          if(matrix.empty()) return false;
        int m=matrix.size();
        int n=matrix[0].size();

         int r=0,c=n-1;
         while(r<m && c>=0){
            if(matrix[r][c]==target) return true;
            if(matrix[r][c]>target)c--;
            else r++;
         }
         return false;
    }
   /*     int l=0,h=(n*m)-1;
        while(l<=h){                // flattening a matrix into array
            int mid=l+(h-l)/2;
            int row_idx=mid/n;             // dividing by no of col gives row idx whereas modulo by no_of_col gives col_idx
            int col_idx=mid%n;
            if(matrix[row_idx][col_idx]==target) return true;
            if(matrix[row_idx][col_idx]>target) h=mid-1;
            else l=mid+1;
        }
        return false;
    }*/
};
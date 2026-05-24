class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix[0].size();i++){
            int k=-1;
            for(int j=0;j<matrix.size();j++){
                k=max(k,matrix[j][i]);
            }
            for(int j=0;j<matrix.size();j++){
            if(matrix[j][i]==-1){
             matrix[j][i]=k;
            }
            }
        }

return matrix;
    }
};
class SubrectangleQueries {
    private:
    vector<vector<int>>rec;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rec=rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        int m=rec.size();
        int n=rec[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i>=row1&&i<=row2)&&(j>=col1&&j<=col2)){
                    rec[i][j]=newValue;
                }
            }
        }
    }
    
    int getValue(int row, int col) {
        return rec[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
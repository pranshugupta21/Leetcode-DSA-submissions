class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int count=0;
        vector<int>histogram(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1) histogram[j]++;
                else histogram[j]=0;
            }
            stack<vector<int>>st;
            st.push({-1,-1,0});// height,previous_index,count
            for(int j=0;j<n;j++){
                while( st.top()[0]>=histogram[j]){
                    st.pop();
                }
                int curr_count=histogram[j]*(j-st.top()[1])+st.top()[2];// any submatrix at bottom corner i,j is equal height*gap + previous_count of index smaller than i,j 
                st.push({histogram[j],j,curr_count});
                count+=curr_count;
            }
        }
        return count;
    }
};
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix[0].size();
        int n=matrix.size();
         vector<int>heights(m,0);
         int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }
                else{                  // row wise maximum area 
                    heights[j]=0;
                }
            }
            maxarea=max(maxarea,largest_rectangleArea(heights));
        }
        return maxarea;
    }
        private: 
        int largest_rectangleArea(vector<int>&heights){
         int area=0;
        stack<int>st;
        for(int i=0;i<=heights.size();i++){
            int currheight=i==heights.size()?0:heights[i];
            while(!st.empty()&& heights[st.top()]>currheight){
                int x=heights[st.top()];
                st.pop();
                if(st.empty()){
                    area=max(area,(x*(i)));
                }
                else{
                   area=max(area,(x*(i-st.top()-1)));
                }
            }  // store in increasing order
            st.push(i);
        }
        return area;

    }
};
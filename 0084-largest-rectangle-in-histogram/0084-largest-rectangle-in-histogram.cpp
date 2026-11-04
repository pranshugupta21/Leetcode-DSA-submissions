class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
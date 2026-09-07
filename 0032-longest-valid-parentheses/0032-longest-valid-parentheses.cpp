class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen=0,n=s.size();
        stack<int>st;
        st.push(-1); // base boundary
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);  // store indices of earliest openings
            else{
              st.pop();       
              if(st.empty()){  // if stack becomes empty means closing brackets are more than openings seq broken
                st.push(i);  // push the new index i.e. new base boundary for future sequence
              }
              else{
                int len=i-st.top();// distance between current position and last unmatched boundary
                maxlen=max(maxlen,len);
              }
            }
        }
        return maxlen;
    }
};
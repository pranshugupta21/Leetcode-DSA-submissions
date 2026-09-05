class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen=0,n=s.size();
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else{
              st.pop();
              if(st.empty()){
                st.push(i);
              }
              else{
                int len=i-st.top();
                maxlen=max(maxlen,len);
              }
            }
        }
        return maxlen;
    }
};
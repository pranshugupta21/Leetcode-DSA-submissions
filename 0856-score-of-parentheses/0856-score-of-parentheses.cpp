class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);// base frame
        for(int i=0;i<s.size();i++){
          if(s[i]=='(') st.push(0);//for nested layer
          else{
            int val=st.top();
            st.pop();
            int score=max(2*val,1); //score of inner brackets if val=0 means no nested brackets then score=1 else score=2*val
            st.top()+=score;   // add this score to previous layer
          }
        }
        return st.top();
    }
};
class Solution {
public:
    string minRemoveToMakeValid(string s) {
       stack<int>st;// store indices of'('
       //mark invalid indices as '*'
       for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(i);
        }
        else if(s[i]==')'){
            if(!st.empty()) st.pop();
            else{
                // stack is empty excess ')'
                s[i]='*';
            }
        }
       }
       while(!st.empty()){
        s[st.top()]='*';   // if stack is not empty extra '('
        st.pop();
       }
       string res="";
       for(char ch:s){
        if(ch!='*')res+=ch;
       }
       return res;
    }
};
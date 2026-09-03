class Solution {
public:
    string removeOuterParentheses(string s) {
        int bal=0;
        string res="";
        for(char ch:s){
            if(ch=='('){
            bal++;
            if(bal>1) res+=ch;
            }
            else if(ch==')'){
                bal--;
                if(bal>0)res+=ch;
            }
        }
        return res;
    }
};
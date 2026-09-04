class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp="";
        int balance=0;
        for(char ch:s){
          if(ch=='('){
            balance++;
            temp+=ch;
          }
          else if(ch==')'){
            if(balance>0) {
                temp+=ch;
                balance--;
            }
            // skip ')' invalid
          }
          else temp+=ch;
        }
       string res="";
       balance=0;
       for(int i=temp.size()-1;i>=0;i--){
        if(temp[i]==')'){
            balance++;
            res+=temp[i];
        }
        else if(temp[i]=='('){
            if(balance>0){
                res+=temp[i];
                balance--;
            }
            // skip '(' extra
        }
        else res+=temp[i];
       }
       reverse(res.begin(),res.end());
       return res;
    }
};
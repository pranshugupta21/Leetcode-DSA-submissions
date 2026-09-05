class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int count=0,open=0;
        for(int i=0;i<n;i++){
          if(s[i]=='(')open++;
          else{  // s[i]==')'
            if(open==0){        // means no '('
               if(i!=n-1 && s[i+1]==')'){  // requires '(' one
                count++;
                i++;
               }
               else{
                count+=2;  // requires '()'

               }
            }
            else{
                if(i!=n-1 && s[i+1]==')') i++;
                else count++;
                open--;
            }
          }
        }
        return count+(open*2); // each unmatched '(' req 2 '))'
    }
};
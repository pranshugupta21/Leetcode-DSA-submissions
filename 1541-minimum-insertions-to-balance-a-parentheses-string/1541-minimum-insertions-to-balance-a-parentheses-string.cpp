class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
          if(s[i]=='(')st.push(s[i]);
          else{  // s[i]==')'
            if(st.empty()){        // means no '('
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
                st.pop();
            }
          }
        }
        return count+(st.size()*2); // each unmatched '(' req 2 '))'
    }
};
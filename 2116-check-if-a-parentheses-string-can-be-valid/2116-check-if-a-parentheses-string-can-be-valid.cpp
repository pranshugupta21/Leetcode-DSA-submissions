class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
       if(n%2==1) return false; //odd size length string cannot be a valid parenthesis
       int balance=0,flips=0;
       for(int i=0;i<n;i++){
            if(locked[i]=='0'){
            flips++;              // left to right checks for excessive ')' 
            }
            else{
                if(s[i]=='(') balance++;
                else balance--;
            }
        if(balance+flips<0) return false;
       }
       
       if(balance>flips) return false;  // at end balance represent unmatched locked brackets if it is grater than flips available then we can't make the string valid
       
       balance=0,flips=0;
        for(int i=n-1;i>=0;i--){          
            if(locked[i]=='0'){              // right to left checks for excessive '(' 
            flips++;
            }
            else{
            if(s[i]==')') balance++;
                else balance--;
            }
        if(balance+flips<0) return false;
       }
       if(balance>flips) return false;
       
       return true;
    }
};
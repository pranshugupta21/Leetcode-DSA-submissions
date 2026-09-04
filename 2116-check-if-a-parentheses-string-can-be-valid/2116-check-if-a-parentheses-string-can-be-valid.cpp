class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
       if(n%2==1) return false;
       int balance=0,flips=0;
       for(int i=0;i<n;i++){
            if(locked[i]=='0'){
            flips++;
            }
            else{
                if(s[i]=='(') balance++;
                else balance--;
            }
        if(balance+flips<0) return false;
       }
       
       if(balance>flips) return false;
       
       balance=0,flips=0;
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0'){
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
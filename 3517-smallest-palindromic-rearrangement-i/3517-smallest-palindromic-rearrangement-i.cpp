class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
         string s1=s.substr(0,n/2);
            sort(s1.begin(),s1.end());
            string s2=s1;
          reverse(s2.begin(),s2.end());
          if(n%2==1){
            return s1+s[n/2]+s2;
          }
         return s1+s2;
        }
        
};
class Solution {
public:
  bool ispalindrome(string &s,int l, int r){
        while(l<r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
       }
    string longestPalindrome(string s) {
       int n=s.size();
       int l=0;
       int start=0;
       int maxlen=1;
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        if(ispalindrome(s,i,j)){
         if(j-i+1>maxlen){
            maxlen=j-i+1;
            start=i;
         }
        }
        }}
        return s.substr(start,maxlen);
        }
       };

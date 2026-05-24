class Solution {
public:
    string longestPalindrome(string s) {
       int n=s.size();
       if(n<=1)return s;
       int start=0;
       int maxlen=1;
      auto expand= [&](int l, int r){
        while(l>=0&&r<n&&s[l]==s[r]){
            if(r-l+1>maxlen){
                maxlen=r-l+1;
                start=l;
            }
            l--;
            r++;
        }
      };
       for(int i=0;i<n;i++){
        expand(i,i);// odd length
        expand(i,i+1); // even length
        }
         return s.substr(start,maxlen);
        }};
        

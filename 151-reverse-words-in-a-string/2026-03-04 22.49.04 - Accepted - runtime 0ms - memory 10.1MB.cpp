class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans="";
        int n=s.size();
        int i=0,r=0,l=0;
        while(i<n){
            while(i<n&&s[i]==' ')i++;
            if(i==n)break;
            l=i;
            r=i;
            while(i<n&&s[i]!=' '){
             r++;
             i++;
            }
            reverse(s.begin()+l,s.begin()+r);
            if(ans!="") ans+=" ";
            ans+=s.substr(l,r-l);
        }
        return ans;
    }
    
};
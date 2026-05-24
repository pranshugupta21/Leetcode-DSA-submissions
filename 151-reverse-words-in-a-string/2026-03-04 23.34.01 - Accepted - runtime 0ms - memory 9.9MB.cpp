class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans="";
        int n=s.size();
        int i=0,r=0,l=0,writepos=0;
        while(i<n){
            while(i<n&&s[i]==' ')i++; // skip spaces
            if(i==n)break;
            if(writepos!=0) {    // add space after each word not before 1st word
                s[writepos++]=' ';}
            l=writepos;
            while(i<n && s[i]!=' '){
            s[writepos++]=s[i++];
            }
            r=writepos;
            reverse(s.begin()+l,s.begin()+r);

        }
        s.resize(writepos);
        return s;
    }
    
};
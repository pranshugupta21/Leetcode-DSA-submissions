class Solution {
public:
    long long countValidSubstrings(string s) {
        int n=s.size();
        long long t=0;
        int la=-1,lb=-1,l=-1,ba=-1;
        for(int r=0;r<n;r++){
            if(s[r]=='a'){
                la=r;
            }
            if(s[r]=='b'){
                if(la!=-1){
                 lb=r;
                 ba=la;
                }
            }
            if(s[r]=='c'){
                if(lb!=-1){
                    l=ba;
                }
            }
            t+=r-l;
        }
        return t;
    }
};
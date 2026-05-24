class Solution {
public:
    bool isIsomorphic(string s, string t) {
       if(s.length()!=t.length()) return false;
 vector<int> mapst(256,-1);
 vector<int> mapts(256,-1);
 for(int i=0;i<s.length();i++){
    char c1=s[i];
    char c2=t[i];
    if(mapst[c1]!=-1&&mapst[c1]!=c2) return false;
    if(mapts[c2]!=-1&&mapts[c2]!=c1) return false;
    mapst[c1]=c2;
    mapts[c2]=c1;
 }
 return true ;
    }
};
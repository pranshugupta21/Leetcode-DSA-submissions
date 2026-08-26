class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int c=0;
        int n=s.size();
        int i=0,j=0;
        string str="";
        while(i<n){
            if(s[i]=='1') c++;
            while(c==k){
             string s1=s.substr(j,i-j+1);
             if(s1.size()<str.size()||str==""||(s1.size()==str.size()&&s1<str)){
                str=s1;
             }
            if(s[j]=='1') c--;
            j++;
            }
            i++;
        }
        return str;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' ') i++;
        int sign=1;
       if (i<n && (s[i] == '+' || s[i] == '-')) {
              if (s[i] == '-') sign = -1;   
               i++;
           }
        string ans="";
        while(i<n && s[i]=='0') i++;
        long long res=0;
        while(i<n){
        if(s[i]<'0' || s[i]>'9') break; 
         if(s[i]>='0'&&s[i]<='9'){
          res=res*10+(s[i]-'0');
          if(sign==1&& res>INT_MAX) return INT_MAX;
          if(sign==-1 && -res<INT_MIN) return INT_MIN;
        }
        i++;
        }
       res=sign*res;
       return res;
    }
};
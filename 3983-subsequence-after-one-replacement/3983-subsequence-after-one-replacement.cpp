class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
   int n=s.size(),m=t.size();
   if(n>m) return false;
   vector<int>prefix(n,m),suffix(n,-1);
   int t_idx=0;
   for(int i=0;i<n;i++){
      while(t_idx<m&&s[i]!=t[t_idx]) {           // Building prefix array
        t_idx++;
      }
      if(t_idx<m){
        prefix[i]=t_idx;
        t_idx++;
      }
      else{
        break;// no char in t is found 
      }
   }
   t_idx=m-1;
   for(int i=n-1;i>=0;i--){
    while(t_idx>=0&&s[i]!=t[t_idx]){               // Building Suffix array
       t_idx--;
    }
    if(t_idx>=0){
        suffix[i]=t_idx;
        t_idx--;
    }
    else{
        break;
        // suffix breaks no char in t is found while searching from s
    }
   }
   for(int i=0;i<n;i++){
    int l=(i==0)? -1:prefix[i-1];
    int r=(i==n-1)? m:suffix[i+1];
    if(r-l>1) return true;
   }
   return false;
}
};
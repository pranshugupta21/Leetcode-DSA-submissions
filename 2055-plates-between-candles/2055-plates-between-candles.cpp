class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int>next(n,n),prev(n,-1),prefixsum(n,0);
        if(s[0]=='|'){
             prev[0]=0;
        }
        else prefixsum[0]=1;
        for(int i=1;i<n;i++){
          if(s[i]=='|') {
            prev[i]=i;
            prefixsum[i]=prefixsum[i-1];
          }
          else {
            prev[i]=prev[i-1];
            prefixsum[i]=1+prefixsum[i-1];
          }
        }
         if(s[n-1]=='|') {
            next[n-1]=n-1;
         }
        for(int i=n-2;i>=0;i--){
          if(s[i]=='|'){
            next[i]=i;
          }
          else {
          next[i]=next[i+1];
        }
    }
    vector<int>ans;
      for(auto &q:queries){
        int left=q[0];
        int right=q[1];
        int start=next[left];
        int last=prev[right];
        if(start>right||last<left) ans.push_back(0);
        else{
        int no_of_stars=prefixsum[last]-prefixsum[start];
        ans.push_back(no_of_stars);
        }
      }
        return ans;
    }
};
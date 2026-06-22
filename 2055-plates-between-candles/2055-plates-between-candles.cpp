class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int>baridx;
        int i=0;
        for(char ch:s){
          if(ch=='|') baridx.push_back(i);
          i++;
        }
        int n=s.size();
        vector<int>ans;
        for(auto &q:queries){
            int l=q[0],r=q[1];
            int firstbar=lower_bound(baridx.begin(),baridx.end(),l)-baridx.begin(); // it is firstbar idx in baridx not string
            int lastbar=upper_bound(baridx.begin(),baridx.end(),r)-baridx.begin()-1;
            if( lastbar<=firstbar)ans.push_back(0);
            else
              ans.push_back(baridx[lastbar]-baridx[firstbar]-(lastbar-firstbar));
            
        }
        return ans;
    }
};
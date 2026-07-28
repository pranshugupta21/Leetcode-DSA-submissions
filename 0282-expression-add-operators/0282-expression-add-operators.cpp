class Solution {
public:
    vector<string>ans;
    vector<string> addOperators(string num, int target) {
        solve(num,target,"",0,0,0);
        return ans;
    }
    void solve(string&s,int target,const string &curr,int i,long long eval ,long long residue){
        if(i==s.length()){
          if(eval==target){
            ans.push_back(curr);
          }
          return;
        }
        string currsubstr;
        long long num=0;
        for(int j=i;j<s.length();j++){
            if(j>i && s[i]=='0') return;  // skip substring with leading Zeros
            currsubstr+=s[j];
            num=num*10+(s[j]-'0');
            if(i==0){
                solve(s,target,currsubstr,j+1,num,num); // First number in the expression (no preceding operator)
            }
            else{
                solve(s,target,curr+'+'+currsubstr,j+1,eval+num,num);
                solve(s,target,curr+'-'+currsubstr,j+1,eval-num,-num);
                solve(s,target,curr+'*'+currsubstr,j+1,((eval-residue)+(residue*num)),residue*num);
            }
        }
          // TC: O(4^N), SC:O(N)
    }
};
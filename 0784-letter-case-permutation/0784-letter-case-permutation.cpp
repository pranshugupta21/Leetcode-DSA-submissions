class Solution {
public:
    void rec(vector<string>&ans,string &s,int i){
        if(i==s.size()){
            ans.push_back(s);
            return;
        }
          if(isdigit(s[i])){
            rec(ans,s,i+1);
          }
          else{ 

          rec(ans,s,i+1);
          // keep current state
           if(islower(s[i])){
            s[i]=toupper(s[i]);
          } 
          else{
            s[i]=tolower(s[i]);
          }
           
           rec(ans,s,i+1);
           // backtrack
            if(islower(s[i])){
            s[i]=toupper(s[i]);
          } 
          else{
            s[i]=tolower(s[i]);
          }
          
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        rec(ans,s,0);
         return ans;
    }
};
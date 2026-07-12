class Solution {
public:
    void rec(vector<string>&ans,string &s,int i){
        if(i==s.size()){
            ans.push_back(s);
            return;
        }
        rec(ans,s,i+1);
          if(isalpha(s[i])){
            s[i]^=32;
            rec(ans,s,i+1);
            s[i]^=32;   //  Backtracking
          }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        rec(ans,s,0);
         return ans;
    }
};
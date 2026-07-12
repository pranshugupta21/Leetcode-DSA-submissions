class Solution {
public:
      unordered_map<char,string>mp;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>ans;
     //   unordered_map<char,string>mp; 
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp="";
        recursion(ans,digits,0,temp);
        return ans;
    }
    private:
      void recursion(vector<string>&ans,string &digits,int i,string &temp){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(auto ch: mp[digits[i]]){
            temp.push_back(ch);
            recursion(ans,digits,i+1,temp);
            temp.pop_back();
        }
    }
};
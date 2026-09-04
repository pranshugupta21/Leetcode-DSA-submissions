class Solution {
public:
    string reverseParentheses(string s) {
        vector<int>start_size;
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                start_size.push_back(res.size());
            }
            else if(s[i]==')'){
              int len=start_size.back();
              reverse(res.begin()+len,res.end());
              start_size.pop_back();
            }
            else res+=s[i];
        }
         return res;
    }
};
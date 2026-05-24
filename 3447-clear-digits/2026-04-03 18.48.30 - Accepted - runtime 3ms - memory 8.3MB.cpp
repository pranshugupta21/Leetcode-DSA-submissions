class Solution {
public:
   string clearDigits(string s) {
    string stack;
    for (int i = 0; i < s.size(); i++){
      if(isdigit(s[i])){
        if(!stack.empty()) stack.pop_back();
      }
      else{
        stack.push_back(s[i]);
      }
    }
    return stack;
    
} 
};
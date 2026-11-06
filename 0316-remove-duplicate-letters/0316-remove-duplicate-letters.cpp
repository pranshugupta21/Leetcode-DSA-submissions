class Solution {
public:
    string removeDuplicateLetters(string s) {
          int seen[27]={0};
        bool instack[27]={false};
        string stack;
        for(char ch:s){
            seen[ch-'a']++;
        }
        for(char ch:s){
            seen[ch-'a']--;
            if(instack[ch-'a'])continue;  // if the character is already in stack donot process
           while(stack.length() && seen[stack.back()-'a']>0 && ch<stack.back()){
            instack[stack.back()-'a']=false;
            stack.pop_back();
           }
            instack[ch-'a']=true;
           stack.push_back(ch);
        }
        return stack;
    }
};
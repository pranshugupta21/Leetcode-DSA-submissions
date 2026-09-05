class Solution {
public:
    int scoreOfParentheses(string s) {
       int depth=0,score=0;
       for(int i=0;i<s.size();i++){
        if(s[i]=='(') depth++; //getting into nested depth
        else{
            depth--;   // ')' encountered so depth decreases
            if(s[i-1]=='(') // If the previous character was '(', we found a core pair "()"
            {
                score+=1<<depth;  // Add 2^depth to the total score
            }
        }
       }
        return score;
    }
};
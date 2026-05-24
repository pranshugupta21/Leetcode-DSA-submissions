class Solution {
public:
    bool buddyStrings(string s, string goal) {
        unordered_set<char>st1;
        unordered_set<char>st2;
        for(char ch: s){
            st1.insert(ch);
        }
          for(char ch: goal){
            st2.insert(ch);
        }
        if(st1.size()==st2.size()){
            if(st1.size()==1&&s.size()>1){
               return true;
            }
            else if(s!=goal){
                return true;
            }
            else{
                return false;
            }
        }
        else return false;
    }
};
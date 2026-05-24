class Solution {
public:
    string customSortString(string order, string s) {
        unordered_set<char>st1;
        for(char c:s){
            st1.insert(c);
        }
        int i=0;
        string ans="";
        while(i<order.size()){
            if(st1.find(order[i])!=st1.end()){
                ans+=order[i]; 
            }
            i++;
        }
        unordered_set<char>st2;
        for(char ch:ans){
            st2.insert(ch);
        }
        for(char c:s){
            if(st2.find(c)==st2.end()){
                ans+=c;
            }
        }
        return ans;
    }
};
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        int i=0;
        string ans="";
        while(i<order.size()){
            if(mp.find(order[i])!=mp.end()){
                while(mp[order[i]]!=0){
                 ans+=order[i]; 
                 mp[order[i]]--;
                }
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
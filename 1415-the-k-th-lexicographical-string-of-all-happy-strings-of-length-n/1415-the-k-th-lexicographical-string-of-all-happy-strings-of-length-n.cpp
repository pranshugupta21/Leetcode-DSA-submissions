class Solution {
public:
    void rec(string &ans,int n,string &temp,int &count,int k){
        if(!ans.empty()) return;
        if(temp.size()==n) {
           count++;
           if(count==k){
            ans=temp;
           }
            return;
        }
       for(char ch:{'a','b','c'}){
        if(temp.empty()||temp.back()!=ch){
            temp.push_back(ch);
            rec(ans,n,temp,count,k);
            temp.pop_back();
        }  
       }
    }
    string getHappyString(int n, int k) {
        if(k>3*(1<<(n-1))) return "";
        string temp="";
          string ans="";
          int cnt=0;
        rec(ans,n,temp,cnt,k);
        return ans;
    }
};
class Solution {
public:
    void rec(vector<string>&ans,int n,string temp){
        if(temp.size()==n) {
            ans.push_back(temp);
            return;
        }
       for(char ch:{'a','b','c'}){
        if(temp.empty()||temp.back()!=ch){
            temp.push_back(ch);
            rec(ans,n,temp);
            temp.pop_back();
        }  
       }
    }
    string getHappyString(int n, int k) {
        if(k>3*(1<<(n-1))) return "";
        vector<string>ans;
        string temp="";
        rec(ans,n,temp);
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};
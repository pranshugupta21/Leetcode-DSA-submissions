class Solution {
public:
    bool ispalindrome(const string &str){
        int n=str.size();
        if(n==1) return true;
        if(n==2) return str[0]==str[1];
        for(int i=0;i<n/2;i++){
            if(str[i]!=str[n-i-1]) return false;
        }
        return true;
    }
    void recur(vector<vector<string>>&ans,vector<string>&curr,string s,int index,int n){
      if(index==n){
        ans.push_back(curr);
        return;
      }
      for(int i=index;i<n;i++){
       string temp=s.substr(index,i-index+1);
        if(ispalindrome(temp)){
          curr.push_back(temp);
        recur(ans,curr,s,i+1,n);  // goes to next charcter where palindrome partioning ended
        curr.pop_back();
        }
      }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>ans;
        vector<string>curr;
        recur(ans,curr,s,0,n);
        return ans;
    }
};
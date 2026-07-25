class Solution {
public:
    bool isMatch(string s, string p) {
        return recur(s,p,0,0);
    }
    private:
    bool recur(string &s ,string &p ,int i,int j){
        if(j==p.size()){
            return i==s.size();
        }
        bool firstmatch=false;
        if( i<s.size() && (s[i]==p[j] || p[j]=='.')) firstmatch=true;

        if(j+1<p.size() && p[j+1]=='*'){
            bool not_take=  recur(s,p,i,j+2);
            bool take=(firstmatch && recur(s,p,i+1,j));
            return take || not_take;
        }
        else{
            return (firstmatch && recur (s,p,i+1,j+1));
        }
    }
};
